// Copyright (C) 2005, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// cruised.c ���ξ���

//#ifdef LONELY_IMPROVED

#include <ansi.h>
#include <mudlib.h>
#include <net/socket.h>
#include <cruise.h>

inherit F_DBASE;

//#include "/adm/etc/database.h"

// ���ξ�����ι�����
// ÿ��վ������ξ��鸺�������֤�����ݴ��䡣�����Ժ�����
// ��������һ���˿ڣ���ѯ��������վ�������
//
// �������Σ�
// ���ĳ��վ���½������վ�����ι�����ʹ���ߣ���վ���ԭ
// ʼվ�����ξ��������ø���ҵ����ݣ����� login & user ��
// �� item �����֣����� dbased �� news ��������õ������ݿ�
// ���������ԾͲ���Ҫ���Ρ�Ȼ�������Щ�����ڱ�վ�㹹��һ
// ����ң���Щ���ݻ���ԭʼվ��ɾ����ȷ����վ����Ψһ�ԣ���
// �˳���ʱ�򲻻ᴫ�ݻ�ԭ�ȵ�վ�㣬�����������ڵ�վ�㡣���
// ʹ�����ַ�ʽ�������Ρ�
//
// ����֧�֣�
// ���ݿ� mysql ���¼��ҵ� id  ���ڵ�վ�㡢�����Լ�������
// ��֤ id ��Ψһ�ԡ����ݿ⻹�账�� dbased �������Ա�֤����
// �����������ܵõ���Чʹ�á�
//
// ��֤���̣�
// ���ξ�������������߾����������֤���󣬲�������Ҫ�����
// վ�������ݡ�������������Ҫ�����û�����վ�� -- �������
// ͨ��һ���ֶν��б��ܡ����������Ժ󽫲����Ƿ�ͨ����������
// Ӧ����Ϣ�����յ����ص���ȷ��Ϣ�Ժ����ξ���������������
// �߾��顣
//
// �����Ķ˿�(��MUD�������˿�Ϊ��׼)
#define CRUISE_PORT                     21

// ������Ȩ�ĵ�ַ
#define AGENT_IP   ({ "127.0.0.1", "61.184.100.7", "219.134.89.94", "202.110.119.87", "218.89.171.162" }) 

#if 0
#define DEBUG_LOG(s)       tell_object(find_player("lonely"), s)
#else
#define DEBUG_LOG(s)
#endif

// �Ӱ汾������ȡ�ص��ļ���׺
#define APPENDFIX       ".cru"
#define STATUS_INIT                     0
#define STATUS_CONNECT                  1
#define MAX_AUTHENTICATING_USER         20

nosave int status = STATUS_INIT;
nosave mixed *cruise_queue = allocate(MAX_AUTHENTICATING_USER);
nosave int next_cruise = 0, queue_pointer = 0;

// ��������ƴ����·��
nosave string bin_path;

nosave int cfd;
nosave string *cruise_file = ({ });
nosave mapping socket_info;

// �ͻ��˵�������Ϣ
nosave mixed *client_info = 0;
// ���͵��ļ�
string *fetch_file_list = 0;

// �ṩ���ⲿ�Ľӿ�
int fetch_file(string file, string sites);
int authenticate_user(object ob, string sites);

protected void send_file(int fd, string file, string peer_name);
protected void server_init();
protected void in_listen_callback(int fd);
protected void in_read_callback(int fd, string str);
protected void in_write_callback(int fd);
protected void in_close_callback(int fd);
protected void parse_cmd(int fd);
protected void debug_info(string msg);
protected void cmd_getfile(int fd, string arg);
protected void cmd_get(int fd, string arg);
protected void cmd_close(int fd, string arg);
protected void syn_receive_result(string str);
protected void syn_fetch_file_from_server();
protected void syn_finish();
protected void sys_info(string msg);
protected void send_command(int fd, string cmd);
protected void send_cruise_file(string id, int fd);
protected int  syn_get_id_data();
protected int  send_error_msg(int fd, string msg);
protected int  send_pending_msg(int fd);
protected int  send_result(int fd, string msg);
protected int  connect_server();
protected int  syn_receive_file(buffer buf);
protected int  send_client_pending_msg();
protected void syn_close_callback(int fd);
protected void send_timeout(int fd);
int clear_syn_info();

int clean_up() { return 1; }

void create() 
{
        seteuid(ROOT_UID);
        bin_path = "binaries";
        set("channel_id", "���ξ���");

        call_out("server_init", 0);
}

protected void remove_from_queue()
{
        mixed *cruise;

        cruise = cruise_queue[queue_pointer];
        if (cruise[USER_ID])
        {        
               //DATABASE_D->db_set_user(cruise[USER_ID], "online", 0);
               //DATABASE_D->db_set_user(cruise[USER_ID], "last_station", LOCAL_STATION);
        }  

        cruise_queue[queue_pointer] = 0;
        queue_pointer = (queue_pointer + 1) % MAX_AUTHENTICATING_USER;
}

void heart_beat()
{
        mixed *cruise; 

        if (status != STATUS_INIT)
                return;

        if (next_cruise == queue_pointer)
        {
                next_cruise = 0;
                queue_pointer = 0;
                cruise_queue = allocate(MAX_AUTHENTICATING_USER);
                set_heart_beat(0);
                return;
        }
        
        if (! fetch_file_list)
                fetch_file_list = 0;

        if (! connect_server())
        {
                cruise = cruise_queue[queue_pointer]; 
                if (cruise[USER_ID]) 
                {
                        //DATABASE_D->db_set_user(cruise[USER_ID], "online", 0); 
                       // DATABASE_D->db_set_user(cruise[USER_ID], "last_station", LOCAL_STATION); 
                }
                log_file("cruise", sprintf("%s Failed to create socket or connect server.\n",
                                   log_time()));
        }
}

mixed query_queue()
{
        return cruise_queue;
}

void restore_cruise()
{
        socket_close(cfd);
        cfd = 0;
        socket_info = ([ ]);
        client_info = ({ });
        next_cruise = 0;
        queue_pointer = 0;
        cruise_queue = allocate(MAX_AUTHENTICATING_USER);
}

void remove(string euid)
{
        if (! this_player())
                return;

        if (sizeof(socket_info) > 0)
                error("���ξ��飺Ŀǰ������վ��ͱ�վ�������ݣ��㲻�ܴݻ����ξ��顣\n");

        if (cfd && arrayp(client_info) && client_info[STATUS] != STATUS_FINISHED)
                error("���ξ��飺Ŀǰ�������������У��㲻�ܴݻ����ξ��顣\n");
}

// �ṩ�汾����
protected void server_init()
{
        int port;

        CHANNEL_D->do_channel(this_object(), "sys", "���ξ����Ѿ�������");

        // ��������ͨѶ��SOCKET
        cfd = socket_create(STREAM_BINARY,
                            "in_read_callback",
                            "in_close_callback" );

        if (cfd < 0)
        {
                log_file("cruise", sprintf("%s Failed to create socket.\n", log_time()));
                return;
        }

        // Ȼ���SOCKET
        port = __PORT__ + CRUISE_PORT;
        if (socket_bind(cfd, port) < 0)
        {
                log_file("cruise", sprintf("%s Failed to bind socket.\n", log_time()));
                socket_close(cfd);
                return;
        }

        // ������
        if (socket_listen(cfd, "in_listen_callback" ) < 0)
        {
                log_file("cruise", sprintf("%s Failed to listen to socket.\n", log_time()));
                return;
        }

        // ��ʼ��������Ϣ
        socket_info = ([ ]);
}

// ����վ������������վ�������
protected void in_listen_callback(int fd)
{
        int new_fd;
        string address;
        string ip;
        int port;

        if ((new_fd = socket_accept(fd, "in_read_callback",
                                        "in_write_callback")) < 0)
                // û�гɹ��Ľ��������������
                return;

        address = socket_address(new_fd);
        if (! stringp(address) || sscanf(address, "%s %d", ip, port) != 2 ||
            // ! CONFIG_D->query(ip))
            member_array(ip, AGENT_IP) == -1)
        {
                // �����ַû�о�����Ȩ
                sys_info(sprintf("վ�� %s ��ַû�о�����Ȩ��", 
                         stringp(address) ? address : "unknow"));            
                socket_close(new_fd);
                return;
        }

        sys_info(sprintf("վ�� %s ���ӱ���������ʼ����ͨѶ��", ip));

        socket_info[new_fd] = allocate(8);
        socket_info[new_fd][STATUS] = STATUS_LOGIN;
        socket_info[new_fd][CMD_BUFFER] = "";
        socket_info[new_fd][CMD_QUEUE] = ({ });
        socket_info[new_fd][PENDING_WRITE] = ({ });
        socket_info[new_fd][SUB_SITES] = "����";
        
        // ����״̬
        socket_info[new_fd][STATUS] = STATUS_WAIT_COMMAND;
        in_write_callback(new_fd);

}

// ������Ϣ
protected void in_read_callback(int fd, mixed mess)
{
        int cc;
        string *cmds;
        mixed  prefix;
        string str;

        if (! arrayp(socket_info[fd]))
                return;

        if (stringp(mess))
                // ���յ����ַ���
                str = mess;
        else
        if (bufferp(mess))
                // ���յ��˻�����
                str = read_buffer(mess, 0, sizeof(mess));
        else
                return;

        if (! str) return;

        str = replace_string( str, "\r", "");
        if (stringp(prefix = socket_info[fd][CMD_BUFFER]))
                str = (string) prefix + str + "\n";
        else
                str += "\n";

        cmds = explode(str, "\n");
        socket_info[fd][CMD_BUFFER] = cmds[sizeof(cmds) - 1];

        if (sizeof(cmds) > 1)
        {
                // ����Щ������뵽���������
                cc = sizeof(socket_info[fd][CMD_QUEUE]);
                socket_info[fd][CMD_QUEUE] += cmds[0..<2];
                if (socket_info[fd][STATUS] == STATUS_WAIT_COMMAND)
                        // ���ڽ�������״̬
                        parse_cmd(fd);
        }
}

// �ɹ�д��
protected void in_write_callback(int fd)
{
        buffer buf;
        string file;
        int pos, len;
        int i;

        for (i = 0; i < 32; i++)
        {
                // ѭ��������Ϣ
                reset_eval_cost();

                // �Ѿ��������ˣ�
                if (! arrayp(socket_info[fd]))
                        // �ǣ��������Ҫ����������
                        return;

                // �������������ͨ��Ϣ�����ҷ��ͳ�ȥ
                while (sizeof(socket_info[fd][PENDING_WRITE]))
                {
                        // ����������Ϣ������֮
                        if (send_pending_msg(fd) != 0)
                                // û�гɹ��ķ��ͣ��ȴ���һ�η���
                                return;
                }

                // ���ݵ�ǰ��״̬���н�һ������
                switch (socket_info[fd][STATUS])
                {
                case STATUS_SENDING:
                        // ���ڷ����ļ�
                        pos = socket_info[fd][FILE_POS];
                        len = socket_info[fd][FILE_SIZE] - pos;
                        if (len > FILE_BLOCK)
                                len = FILE_BLOCK;
                        if (len > 0)
                        {
                                buf = read_buffer((string) socket_info[fd][FILE_NAME], pos, len);
                                if (sizeof(buf) != len)
                                        // ��ȡû����ȫ�ɹ�����д�㷢�͡�
                                        buf = allocate_buffer(len);
                                // �ж���β����Ľ��
                                switch (socket_write(fd, buf))
                                {
                                case EESUCCESS:
                                        // �ƶ��α�
                                        pos += len;
                                        break;

                                case EECALLBACK:
                                        // �ƶ��α�
                                        pos += len;

                                        // �ȴ�CALLBACK���Ȳ���������
                                        socket_info[fd][FILE_POS] = pos;
                                        return;

                                case EEWOULDBLOCK:
                                        // ����æ
                                        call_out("in_write_callback", 2, fd);
                                        return;

                                default:
                                        // ����ʧ�ܣ��ȴ��´�callback
                                        return;
                                }
                        }

                        // �ж��ļ��Ƿ������
                        if ((socket_info[fd][FILE_POS] = pos) >=
                            socket_info[fd][FILE_SIZE])
                        {  
                                file = socket_info[fd][FILE_NAME];
                                // ��ʱȡ���˽������ε������ļ�������ȡ����ɾ�������ε������ļ�
                                // rename(file, file + ".oo");  
                                                              
                                // �ļ��Ѿ�������ϣ�����״̬
                                socket_info[fd][STATUS] = STATUS_WAIT_COMMAND;
                                if (! sizeof(socket_info[fd][CMD_QUEUE]))
                                        // �Ѿ�û�д������������
                                        return;

                                // �����������ΪʲôҪ��
                                // this_object() ���к��У�
                                // ����ǲ���ʡ�Եģ���Ϊ��
                                // ���������ֵĺ����Ϳ��Ը�
                                // ��previous_object() �ֱ�
                                // �Ƿ���������callback�ڡ�
                                this_object()->parse_cmd(fd);

                                // ������ѭ�����ᴦ����������Ľ��
                        }

                        // ���ʹ������
                        break;
        
                default:
                        // δ����״̬���޲���
                        return;
                }

                // һ�δ���(switch)��ϣ�ѭ����������
        }

        // ����̫����
        debug_info("�� SOCKET д������̫�࣬�ݻ���");
        call_out("in_write_callback", 1, fd);
}

// ���ӶϿ�
protected void in_close_callback(int fd)
{
        string address;

        address = socket_address(fd);
        if (stringp(address))
                sscanf(address, "%s %*d", address);
        else
                address = "unknow";

        sys_info(sprintf("վ�� %s �ͱ�վ�Ͽ������ӡ�", address));

        // �����Ϣ
        map_delete(socket_info, fd);
}

// �� LOGIN_D ���õĽӿ�
int authenticate_user(object ob, string sites)
{
        int is_cruise;
        int next_next;       
        string cruise_id;
                
        if (! stringp(cruise_id = ob->query("id")))
                return 0;
                
        if (! stringp(sites) /*|| sites == LOCAL_STATION*/)
        {
                write(HIY "���������ڵ�վ��û�еõ�ȷ�ϻ����ڱ�վ�����α�ǿ����ֹ��\n" NOR);
                return 0;
        }
        
        //if (! DATABASE_D->query_db_status())
                //DATABASE_D->connect_to_database();      
        
        //is_cruise = DATABASE_D->db_query_user(cruise_id, "online");
                              
        if (is_cruise == 3)
        {
                write(HIY "����ͬʱ�����θ����ﵵ�������α�ǿ����ֹ��\n" NOR);
                return 0;
        }
 
        next_next = (next_cruise + 1) % MAX_AUTHENTICATING_USER;
        if (next_next == queue_pointer) 
        {
                // ͬʱ�������ε����������������
                write(HIY "���ζ������������Ժ����ٽ����������Ρ�\n" NOR);
                return 0;
        }
        
        cruise_queue[next_cruise] = allocate(2);
        cruise_queue[next_cruise][USER_ID] = cruise_id;
        cruise_queue[next_cruise][USER_SITE] = sites;
        next_cruise = next_next;

        //DATABASE_D->db_set_user(cruise_id, "online", 3);

        write(HIR "����վ���������ȡ�����������..�����Ժ��ٳ��Ե�½��\n" NOR);
        
        set_heart_beat(1);
        return 1;
}                         

// ��վ��������˷�������
void send_command(int fd, string cmd)
{
        if (! fd)
                // ��鵱ǰ���ӵ�CFD
                if (! (fd = cfd)) return;
                

        cmd += "\n";
        if (sizeof(client_info[PENDING_WRITE]))
        {
                // �Ѿ���������Ҫ���͵������ˣ���η��͵���
                // ��������
                client_info[PENDING_WRITE] += ({ cmd });
                return;
        }

        switch (socket_write(fd, cmd))
        {
        case EESUCCESS:
        case EECALLBACK:
                // ���ͳɹ���
                return;

        case EEWOULDBLOCK:
                // ������������
                client_info[PENDING_WRITE] += ({ cmd });
                call_out("syn_write_callback", 2, fd);
                return;

        default:
                // ����ʧ��
                client_info[PENDING_WRITE] += ({ cmd });
                return;
        }
}

// ������������Ϣ

protected int send_pending_msg(int fd)
{
        string result;

        result = socket_info[fd][PENDING_WRITE][0];

        switch (socket_write(fd, result))
        {
        case EESUCCESS:
                // ���ͳɹ���
                socket_info[fd][PENDING_WRITE] = socket_info[fd][PENDING_WRITE][1..<1];
                return 0;

        case EECALLBACK:
                // ��Ҫ�ȴ�
                socket_info[fd][PENDING_WRITE] = socket_info[fd][PENDING_WRITE][1..<1];
                return -1;

        case EEWOULDBLOCK:
                // ������������
                call_out("in_write_callback", 2, fd);
                return -1;

        default:
        }
}

// ��������򵥣������ó�����﷨������
protected void parse_cmd(int fd)
{
        string cmd;
        string word, arg;

        // ȡ��һ��������д���
        cmd = socket_info[fd][CMD_QUEUE][0];
        socket_info[fd][CMD_QUEUE] = socket_info[fd][CMD_QUEUE][1..<1];

        if (sscanf(cmd, "%s %s", word, arg) != 2)
        {
                word = cmd;
                arg = 0;
        }

        switch (word)
        {
        case "getfile":
                cmd_getfile(fd, arg);
                break;
                                
        case "get":
                cmd_get(fd, arg);
                break;

        case "close":
                cmd_close(fd, arg);
                break;
        }
}

// ��ȡ�����������
protected void cmd_getfile(int fd, string arg)
{
        string id;
        string mudn;

        if (stringp(arg) && sscanf(arg, "%s from %s", id, mudn) == 2)
        {
                sys_info(sprintf("վ�� %s���ڶ�ȡ��֤��Ϣ��׼���������(%s)���ݡ�", mudn, id));
                socket_info[fd][SUB_SITES] = mudn;
        }

        send_cruise_file(id, fd);
        return;
}

// ��ȡĳһ���ļ�
protected void cmd_get(int fd, string arg)
{
        string ban;
        int last;

        // �鿴�ļ�
        if (! arg || arg[0] != '/')
        {
                send_error_msg(fd, sprintf("no such file(%O).\n", arg));
                return;
        }

        last = strlen(arg) - 2;
        
        // ���Ͱ汾��¼�µ��ļ�
        send_file(fd, arg, arg);
}

// �ر�����
protected void cmd_close(int fd, string arg)
{
        string address;

        address = socket_address(fd);
        if (stringp(address))
                sscanf(address, "%s %*d", address);
        else
                address = "unknow";

        sys_info(sprintf("վ�� %s �ͱ�վ����������ϡ�", address));

        send_result(fd, RESULT_FINISH "ok\n");
}

// ��Է�����һ�������Ϣ
protected int send_result(int fd, string msg)
{
        string result;

        result = sprintf("%-" + (NORMAL_RESULT_LEN - 1) + "s.", msg);

        if (sizeof(socket_info[fd][PENDING_WRITE]))
        {
                // �Ѿ���������Ҫ���͵������ˣ���η��͵���
                // ��������
                socket_info[fd][PENDING_WRITE] += ({ result });
                return -1;
        }

        switch (socket_write(fd, result))
        {
        case EESUCCESS:
                // ���ͳɹ���
                return 0;

        case EECALLBACK:
                // ��Ҫ�ȴ�
                // socket_info[fd][PENDING_WRITE] += ({ result });
                return -1;

        case EEWOULDBLOCK:
                // ������������
                socket_info[fd][PENDING_WRITE] += ({ result });
                call_out("in_write_callback", 2, fd);
                return -1;

        default:
                socket_close(fd);
        }
}

// ��Է�����һ��������Ϣ
protected int send_error_msg(int fd, string msg)
{
        return send_result(fd, RESULT_ERR + msg);
}

// ��Է�����һ���ļ�
protected void send_file(int fd, string file, string peer_name)
{
        int fs;

        // ֱ�ӷ���
        if ((fs = file_size(file)) < 0)
        {
                send_error_msg(fd, sprintf("read file(%s) error.\n", file));
                return;
        }

        // ����״̬��Ȼ�����ȷ����ļ��ĳ���
        socket_info[fd][FILE_NAME] = file;
        socket_info[fd][FILE_SIZE] = fs;
        socket_info[fd][FILE_POS] = 0;
        socket_info[fd][STATUS] = STATUS_SENDING;
        if (send_result(fd, sprintf(RESULT_FILE "%s %d\n", peer_name, fs)) == 0 &&
            previous_object() != this_object())
                // �ɹ������˵�Ӧ�𣬲��ҵ�ǰ������in_write_callback
                // ���ý��룬����������ļ�
                in_write_callback(fd);     
}

// �����ļ�����
protected int syn_receive_file(buffer buf)
{
        mixed *st;
        string file;
        int len;
        int sl;

        file = client_info[FILE_NAME];
        len =  client_info[FILE_SIZE] - client_info[FILE_POS];
        if (len > sizeof(buf))
                // ����Ҫ��buf�е�����ȫ��д��
                len = sizeof(buf);

        write_buffer(file + APPENDFIX,
                     client_info[FILE_POS], buf[0..len - 1]);
        client_info[FILE_POS] += len;
        if (client_info[FILE_POS] < client_info[FILE_SIZE])
                // �ļ���û�н������
                return len;

        // �ɹ���ȡ�ļ����
        log_file("cruise", sprintf("%s got file %s.\n",
                                    log_time(), client_info[FILE_NAME]));
        client_info[FILE_POS] = 0;
        client_info[FILE_NAME] = 0;
        client_info[FILE_SIZE] = 0;

        // �鿴��ǰ��״̬
        switch (client_info[STATUS])
        {
        case STATUS_SYN:
                // ���ļ������޸�Ϊ����������
                rm(file);
                rename(file + APPENDFIX, file);

                // �������ļ���һ��C�ļ�����ô�ұ���ɾ��
                // ����BIN �ļ�����Ϊ����Ҫ���±�������
                sl = strlen(file) - 2;
                if (sl > 0 && file[sl] == '.' && file[sl + 1] == 'c')
                        rm(bin_path + file[0..sl] + "b");
                break;

        default:
                // �����״̬
        }

        // ����ʹ�õ�BUFFER�ĳ���
        return len;
}

protected int connect_server()
{
        string sites;
        string addr;
        int port;
        int ret_val;
        mixed *cruise;

        cruise = cruise_queue[queue_pointer];

        CHANNEL_D->do_channel(this_object(), "sys", "����ϵͳ������<" +
                              cruise[USER_SITE] + ">��ȡ�������ϡ�");
                                              
        // �����汾ͨѶ��SOCKET
        cfd = socket_create(STREAM_BINARY,
                            "syn_read_callback",
                            "syn_close_callback" );

	if (cfd < 0)
        {
                if (cruise[USER_ID])
                {
                        //DATABASE_D->db_set_user(cruise[USER_ID], "online", 0);
                        //DATABASE_D->db_set_user(cruise[USER_ID], "last_station", LOCAL_STATION); 
                }
                        
                log_file("cruise", sprintf("%s Failed to create socket.\n",
                                            log_time()));
                return 0;
	}
        // Ŀ��Ϊ�رո� cfd��ϵͳ������cfd�����ﱻ�ı��ˣ����Լ�����cfd���ᱻ�ر�
        status = STATUS_CONNECT;
        remove_call_out("send_timeout");
        call_out("send_timeout", 180, cfd);
        
        // ��ʼ���ͻ�����Ϣ
        client_info = allocate(8);
        client_info[STATUS] = STATUS_CONNECTING;
        client_info[FILE_NAME] = 0;
        client_info[FILE_POS] = 0;
        client_info[FILE_SIZE] = 0;
        client_info[RESULT_BUFFER] = "";
        client_info[PENDING_WRITE] = ({ });

        sites = cruise[USER_SITE];
        port = __PORT__ + CRUISE_PORT;
        // ���ɰ汾�����������ӵ�ַ
        addr = sprintf("%s %d", sites, port);

        ret_val = socket_connect(cfd, addr,
                                 "syn_read_callback",
                                 "syn_write_callback");
        if (ret_val != EESUCCESS)
        {
                status = STATUS_INIT;
                
                if (cruise[USER_ID])
                {
                        //DATABASE_D->db_set_user(cruise[USER_ID], "online", 0);
                        //DATABASE_D->db_set_user(cruise[USER_ID], "last_station", LOCAL_STATION);
                }
                    
                log_file("cruise", sprintf("%s Failed to connect server.\n",
                                            log_time()));
                return 0;
        }

        log_file("cruise", sprintf("%s connecting to server %s.\n",
                                    log_time(), addr));
        return 1;
}

// �����ؽ��յ�����������վ�������
protected void syn_read_callback(int fd, buffer buf)
{
        string str;
        int len;
        int ver;
        string msg;

        if (fd != cfd || ! bufferp(buf)) return;

        DEBUG_LOG(sprintf(HIC "incoming: buf = %O(%d)\n" NOR, buf, sizeof(buf)));
        
        do
        {
                if (! client_info[FILE_NAME])
                {
                        // û���ļ����֣����յ�����ͨӦ����Ϣ
        
                        // ������Ӧ�ôӻ������ж������ֽ���Ŀ����Ϊ
                        // ���ܲ���һ�λ����ͨ��Ӧ����Ϣ������ҽ�
                        // ��Щ��Ϣ�ۼƵ�RESULT_BUFFER�У� һֱ����
                        // ���������ֽ�Ϊֹ����ô����δӻ���������
                        // ����Ӧ���Ƕ��ٸ��ֽڣ���Ӧ�ü��㡣���б�
                        // ����FILE_POS�е������Ѿ��������ַ���
                        len = NORMAL_RESULT_LEN - client_info[FILE_POS];
                        if (len > sizeof(buf))
                                // ���û����ô���ֽڿ������Ҷ�
                                len = sizeof(buf);
                        client_info[FILE_POS] += len;
                        client_info[RESULT_BUFFER] += read_buffer(buf, 0, len);
                        // ȡʣ���buffer
                        buf = buf[len..<1];
        
                        if (client_info[FILE_POS] >= NORMAL_RESULT_LEN)
                        {
                                // ������һ��ͨ���ķ�����Ϣ��������
                                // �û�������
                                str = client_info[RESULT_BUFFER];
                                client_info[RESULT_BUFFER] = "";
                                client_info[FILE_POS] = 0;
        
                                // ������յ��Ľ����Ϣ
                                syn_receive_result(str);
                        }
                }
        
                DEBUG_LOG(sprintf("buf = %O(%d) ... file_name = %O(%d)\n",
                                                          buf, sizeof(buf),
                                                          client_info[FILE_NAME],
                                                          client_info[FILE_POS]));
                if (bufferp(buf) && client_info[FILE_NAME])
                        // �����ļ�
                        buf = buf[syn_receive_file(buf)..<1];

                // ���buf��Ϊ�գ����������
        } while (sizeof(buf) && client_info[STATUS] != STATUS_FINISHED);
}

// ����ʱ�ͻ������ӵ�д�ص�����
void syn_write_callback(int fd)
{
        if (fd != cfd)
        {
                log_file("cruise", sprintf("socket error: fd = %d vfd = %d\n", fd, cfd));
                return;
        }

        while (sizeof(client_info[PENDING_WRITE]))
        {
                // ����������Ϣ������֮
                if (send_client_pending_msg() != 0)
                        // û�гɹ��ķ��ͣ��ȴ���һ�η���
                        return;
        }

        // ���ݵ�ǰ��״̬����
        switch (client_info[STATUS])
        {
        case STATUS_CONNECTING:
                if (fetch_file_list)
                {
                        // ָ�����ĳЩ�ļ�
                        syn_fetch_file_from_server();
                        break;
                }     
                // �ո����ӣ�����ȡ����������ݵ�����
                send_command(fd, sprintf("getfile %s from %s(%s)", cruise_queue[queue_pointer][USER_ID],
                                         /*LOCAL_MUD_NAME()*/"mymud", INTERMUD_MUD_NAME,
                                         __PORT__));
                client_info[STATUS] = STATUS_GET_ITEM;
                sys_info("�汾����ɹ��ĺͷ�����������ͨѶ��");                     
                break;
        default:
                return;                
        }
}
// ϵͳ��Ϣ
protected void sys_info(string msg)
{
        CHANNEL_D->do_channel(this_object(), "sys", msg);
}

// ������Ϣ
protected void debug_info(string msg)
{
        CHANNEL_D->do_channel(this_object(), "debug", msg);
}

// �ͻ��˷�����������Ϣ

protected int send_client_pending_msg()
{
        string msg;

        msg = client_info[PENDING_WRITE][0];
        switch (socket_write(cfd, msg))
        {
        case EESUCCESS:
                // ���ͳɹ���
                client_info[PENDING_WRITE] = client_info[PENDING_WRITE][1..<1];
                return 0;

        case EECALLBACK:
                // ��Ҫ�ȴ�
                client_info[PENDING_WRITE] = client_info[PENDING_WRITE][1..<1];
                return -1;

        case EEWOULDBLOCK:
                // ������������
                call_out("syn_write_callback", 2, cfd);
                return -1;

        default:
                // ����ʧ��
                return -1;
        }
}

// ͬ��ʱ�ͻ������ӵĶ��ص�����
// ���ڷ��������ܻ᷵���������ݣ�1 ��ͨӦ����Ϣ  2 ��������
// �����ݡ���˽��պ�������״̬�е��ļ����ִ��������������
// ����״̬��������ļ����֣���ô����Ϊ�ǽ����ļ��У����û
// �У����ǽ�����ͨӦ����Ϣ����ͨӦ����Ϣһ���ǹ̶����ֽڣ�
// ��ASCII ��ʽ��š����һ�ν���û�������������ֽڣ���ô��
// �Ƚ�������FILE_POS���档

protected void syn_receive_result(string str)
{
        string file;
        string msg;
        string ver;        
        int len;

        if ((len = strsrch(str, '\n')) == -1)
        {
                // ���ص���Ϣ����ȷ - �������'\n'
                log_file("cruise", sprintf("%s respond without '\\n' from server: %s.\n",
                                            log_time(), str));
                DEBUG_LOG(sprintf(HIR "error syntax str = %s\n" NOR, str));
                return;
        }
        if (! len) return;
        str = str[0..len - 1];

        DEBUG_LOG(sprintf("str = %s\n", str));

        if (sscanf(str, RESULT_ERR "%s", msg))
        {
                // �����˴����ȼ�¼������־
                log_file("cruise", sprintf("%s error respond: %s\n",
                                            log_time(), msg));
                DEBUG_LOG(str + "\n");
        }

        // ���ݵ�ǰ��״̬���д���
        switch (client_info[STATUS])
        {
        case STATUS_GET_ITEM:
                if (sscanf(str, RESULT_CRUISE "%s", ver))
                {
                        // cruise_file = explode(ver, "|"); 
                        if (ver != "SEND_CRUISE_FILE_OK")    
                                cruise_file += ({ ver });                               
                        else
                                syn_get_id_data();                      
                }                
                                                
                // syn_get_id_data();
                // û�з������������������Ϣ
                // log_file("cruise", sprintf("%s can not get cruise. server report: %s\n",
                //                            log_time(), str));

                // ��ô�죿ֻ�н�������
                // syn_finish();
                break;
                
        case STATUS_SYN:
                // �����ļ��ĳ���
                if (! sscanf(str, RESULT_FILE "%s %d", file, len))
                {
                        if (sscanf(str, RESULT_FINISH "%*s"))
                        {
                                log_file("cruise", sprintf("%s cruise synchronized.\n",
                                                            log_time()));
                                syn_finish();
                        }

                        break;
                }

                DEBUG_LOG(sprintf("file: %s len = %d\n", file, len));

                // ��¼�Ľ����ļ�״̬����Ϣ

                // ��¼���������ļ�����Ϣ
                client_info[FILE_NAME] = file;
                client_info[FILE_POS] = 0;
                client_info[FILE_SIZE] = len;

                // ����У�ɾ������ļ�����ʱ�ļ�
                rm(file + APPENDFIX);

                sys_info(sprintf("getting(%s)...", file));
                break;

        default:
                // ��Ӧ�ý��յ���Ϣ
        }
}

// �������ݽ���
// ����ʱ���ܳɹ��������ˣ�Ҳ����û�С�
protected void syn_finish()
{
        mixed *cruise;

        seteuid(ROOT_UID);
        sys_info("���ξ��飺����������ݽ�����");

        cruise = cruise_queue[queue_pointer];
                
        if (cruise[USER_ID])
        {        
                //if (! DATABASE_D->query_db_status())
                        //DATABASE_D->connect_to_database();   
                
                //DATABASE_D->db_set_user(cruise[USER_ID], "online", 0);
               // DATABASE_D->db_set_user(cruise[USER_ID], "last_station", LOCAL_STATION);
        }

        if (cfd) { socket_close(cfd); cfd = 0; }
 
        cruise_file = ({ });
          
        client_info[STATUS] = STATUS_FINISHED;
        client_info[FILE_NAME] = 0;
        client_info[FILE_POS] = 0;
        client_info[FILE_SIZE] = 0;
        client_info[PENDING_WRITE] = ({ });
        client_info[RESULT_BUFFER] = "";
        remove_from_queue();
        status = STATUS_INIT;  // by Lonely
        fetch_file_list = 0;
}

// �ӷ������ϻ�ȡһ���ļ�
protected void syn_fetch_file_from_server()
{
        int i;

        client_info[STATUS] = STATUS_SYN;

        for (i = 0; i < sizeof(fetch_file_list); i++)
        {
                if (fetch_file_list[i][0] != '/')
                        fetch_file_list[i] = "/" + fetch_file_list[i];
                send_command(cfd, "get " + fetch_file_list[i]);
        }

        send_command(cfd, "close");
}

protected void send_cruise_file(string cruise_id, int fd)
{
        object ob;
        mapping summon, whistle;
        string *ks;
        string *fs;
        string msg;
        string file;
        int i;

        msg = "";
        fs = ({ });
                
        ob = UPDATE_D->global_find_player(cruise_id);
        summon = ob->query("can_summon");
        whistle = ob->query("can_whistle");
        UPDATE_D->global_destruct_player(ob);
        
        if (objectp(ob = find_player(cruise_id)))
        {
                tell_object(HIY "����������������������Σ�ϵͳǿ��ʹ�����ߡ�\n" NOR);             
                ob->save();
                destruct(ob);
        }

        if (mapp(summon))
        {
                ks = keys(summon);
                for (i = 0; i < sizeof(ks); i++)
                {
                        file = summon[ks[i]] + ".c";
                        if (file_size(file) > 0)
                        {
                                if (ob = find_object(file))
                                        destruct(ob);

                                send_result(fd, sprintf(RESULT_CRUISE "%s\n", file));   
                                // fs += ({ file });
                        }
                }
        }        
        if (mapp(whistle))
        {
                ks = keys(whistle);
                for (i = 0; i < sizeof(ks); i++)
                {
                        file = whistle[ks[i]] + ".c";
                        if (file_size(file) > 0)
                        {
                                if (ob = find_object(file))
                                        destruct(ob);

                                send_result(fd, sprintf(RESULT_CRUISE "%s\n", file));   
                                // fs += ({ file });
                        }
                }
        }                        

        file = sprintf(DATA_DIR "beast/%s", cruise_id + "-beast" + __SAVE_EXTENSION__);
        if (file_size(file) > 0)
                send_result(fd, sprintf(RESULT_CRUISE "%s\n", file)); 
                // fs += ({ file });
        /*
        if (sizeof(fs) >= 2) 
                msg += implode(fs[0..sizeof(fs) - 1], "|"); 
        else 
        if (sizeof(fs) == 1)
                msg += fs[0]; 

        if (! msg)
                send_result(fd, RESULT_NO_CRUISE "no file need to cruise\n");
        else
                send_result(fd, sprintf(RESULT_CRUISE "%s\n", msg));       
        */     

        send_result(fd, sprintf(RESULT_CRUISE "%s\n", "SEND_CRUISE_FILE_OK"));  
        return;
}

int syn_get_id_data()
{
        string file;
        int i;
        mixed *cruise;

        cruise = cruise_queue[queue_pointer];
        
        /*if (TX_SAVE && CRUISE_USER_DATA)
        {
                file = sprintf(DATA_DIR "login/%c/%s", cruise[USER_ID][0], cruise[USER_ID] + __SAVE_EXTENSION__);
                assure_file(file);     
                fetch_file_list = ({ file });  
                file = sprintf(DATA_DIR "user/%c/%s", cruise[USER_ID][0], cruise[USER_ID] + __SAVE_EXTENSION__);
                assure_file(file);     
                fetch_file_list += ({ file }); 
        } else*/
                fetch_file_list = ({ });              
                
        if (arrayp(cruise_file) && sizeof(cruise_file) > 0)
        {
                for (i = 0; i < sizeof(cruise_file); i++)
                {
                        file = cruise_file[i];
                        if (file[0] != '/')
                                file = "/" + file;
                        assure_file(file);
                        fetch_file_list += ({ file });   
                }
        }        

        sys_info(sprintf("����վ�� %s �ɹ�����ʼ�������� %s �����ݡ�", cruise[USER_SITE], cruise[USER_ID]));
        syn_fetch_file_from_server();
        return 1;
}

int fetch_file(string file, string sites)
{
        int next_next;
        
        next_next = (next_cruise + 1) % MAX_AUTHENTICATING_USER;
        if (next_next == queue_pointer) 
        {
                // ͬʱ�������ε����������������
                write(HIY "���ζ������������Ժ����ٽ����������Ρ�\n" NOR);
                return 0;
        }

        fetch_file_list = ({ file }); 
                
        cruise_queue[next_cruise] = allocate(2);
        cruise_queue[next_cruise][USER_ID] = 0;
        cruise_queue[next_cruise][USER_SITE] = sites;
        next_cruise = next_next;

        write("�������ӷ�������ȡ�ļ���\n");        
        set_heart_beat(1);
        return 1;
}


protected void send_timeout(int fd)
{
        socket_close(fd);
        syn_close_callback(fd);
}

// ����ʱ�ͻ������ӶϿ��Ļص�����
protected void syn_close_callback(int fd)
{   
        remove_call_out("send_timeout");
        // ��ֹ���������б��ر�
        if (queue_pointer == next_cruise &&
            status != STATUS_INIT)
                return;
                
        if (fd != cfd) return;
        
        cfd = 0;
        remove_from_queue();
        status = STATUS_INIT;
}

int clear_syn_info()
{
        int result;
        int fd;

        if (previous_object() && ! is_root(previous_object()))
                return 0;

        // �������ˣ�����׽��ֵ�������Ϣ

        if (sizeof(socket_info) > 0)
        {
                foreach (fd in keys(socket_info))
                        if (intp(fd)) socket_close(fd);

                socket_info = ([ ]);
                return 1;
        }

        return 0;


        // �ͻ��ˣ�������ε�SOCKET����Ϣ
        if (cfd)
        {
                log_file("cruise", sprintf("%s ��ͣ���������ݵĲ�����\n", log_time()));
                syn_finish();
                return 1;
        }

        return 0;
}

mixed query_socket_info()
{
        if (previous_object() && ! is_root(previous_object()))
                return 0;
        
        return socket_info;
}

mixed query_client_info() { return client_info; }
int query_cfd() { return cfd; }

//#endif
