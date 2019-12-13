// fileserver By Wenwu On 2006��7��2��
// �ļ����ͷ��� v1.0.0.0
// Ϊ�˷�����·�վ�汾����д��һ�����������

#define FILE_SERVER_DEBUG
#define FILE_SERVER_PASSWD "Ll12345"

#include <ansi.h>
#include <net/socket.h>
#include <runtime_config.h>

inherit F_DBASE;

// ��վͨѶ SOCKET
int send_file_socket;
// ���ӵ�Զ�� IP
string to_addr;
// ���ӵ�Զ�� �˿�
int send_file_port;
// ��վͨѶ SOCKET
int server_socket;

// ��վͨѶ�˿�
#ifdef __SENSIBLE_MODIFIERS__
int server_port = get_config(15);
#else
int server_port = get_config(__MUD_PORT__);
#endif

// �ļ�����
string send_file_arg = "";
// �ļ�·��(��ʼ��Ϊ��ʱ�ļ� /temp.c)
string send_file_name = "/temp.c";
// �ļ�·��(��ʼ��Ϊ��ʱ�ļ� /temp.c)
string save_file_name = "/temp.c";
// ͨѶ����
string server_passwd = "12345";
// ���յ�������
string all_file_arg = "";

// �ڲ�ʹ�ú���
protected void setup();
protected void listen_server();
protected void server_listen_callback(int fd);
protected void server_write_callback(int fd);
protected void server_read_callback(int fd, mixed mess);
protected void server_close_callback(int fd);
void file_resolve_callback(string address, string resolved, int key);
void file_read_callback(int fd, string mess);
void file_write_callback(int fd);
void file_close_callback(int fd);
private void send_to_remote();

// �ⲿʹ�ú���
void connect_to(string arg, string file);

void create()
{
	seteuid(getuid());

	set("channel_id", "�������");
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ������Ѿ�������\n"NOR);

	// ��ʼ��
	setup();
}

protected void setup()
{
	// ��ʼ����
	call_out("listen_server", 3);
	return;
}

protected void listen_server()
{
	// �������� SOCKET
	server_socket = socket_create(STREAM, "server_read_callback", "server_close_callback");

	if ( server_socket < 0 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺴������� SOCKET ʧ�ܡ�\n"NOR);
		log_file("/net/net_server", sprintf("�������� SOCKET ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( socket_bind(server_socket, server_port) < 0 )
	{
		// �ر� SOCKET
		if ( server_socket )
			socket_close(server_socket);
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ������������� SOCKET ʧ�ܡ�\n"NOR);
		log_file("/net/net_server", sprintf("�������� SOCKET ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �ѹرա�\n"NOR);
		log_file("/net/net_server", sprintf("���� SOCKET �ѹر� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	// ��ʼ����
	if ( socket_listen(server_socket, "server_listen_callback" ) < 0 )
	{
		// �ر� SOCKET
		if ( server_socket )
			socket_close(server_socket);
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET ʧ�ܡ�\n"NOR);
		log_file("/net/net_server", sprintf("���� SOCKET ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �ѹرա�\n"NOR);
		log_file("/net/net_server", sprintf("���� SOCKET �ѹر� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺿�ʼ���� SOCKET ��\n"NOR);
	log_file("/net/net_server", sprintf("��ʼ���� SOCKET On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

protected void server_listen_callback(int fd)
{
	int new_fd;

	if ( (new_fd = socket_accept(fd, "server_read_callback", "server_write_callback")) < 0 )
		return;

	server_write_callback(new_fd);
#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET ��ȨԶ��λַ�������ļ���\n"NOR);
	log_file("/net/net_server", sprintf("���� SOCKET ��ȨԶ��λַ�������ļ� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

protected void server_write_callback(int fd)
{
	switch (socket_write(fd, "�ɹ���������"))
	{
		// ���ͳɹ�
		case EESUCCESS:
		case EECALLBACK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �ɹ�Ӧ����Ϣ��\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET �ɹ�Ӧ����Ϣ On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		
		// ������������
		case EEWOULDBLOCK:
			call_out("server_write_callback", 3);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET Ӧ����Ϣ��������������·��͡�\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET Ӧ����Ϣ��������������·��� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
			
		default:
			// ����ʧ��
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET Ӧ����Ϣʧ�ܡ�\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET Ӧ����Ϣʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
	}
}

protected void server_read_callback(int fd, mixed mess)
{
	string file_name, file_arg, pass, *file_dir, file_dir_add;
	int i;

	if ( !stringp(mess) )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �����ļ�ʧ�ܡ�\n"NOR);
		log_file("/net/net_server", sprintf("���� SOCKET �����ļ�ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( all_file_arg == "" )
	{
		if ( sscanf(mess, "@@@%s#@#%s@@@##%s", file_name, pass, file_arg) != 3 )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET ������Ϣ��ʧ�ܡ�\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET ������Ϣ��ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		}

		if ( pass != FILE_SERVER_PASSWD )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷���������֤ʧ�ܣ����� SOCKET �ܾ����ļ����ա�\n"NOR);
			log_file("/net/net_server", sprintf("����������֤ʧ�ܣ����� SOCKET �ܾ����ļ����� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		}

#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷���������֤ͨ������ʼ�����ļ���\n"NOR);
		log_file("/net/net_server", sprintf("����������֤ͨ������ʼ�����ļ� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

		save_file_name = file_name;
		// �ļ�·�������ڣ����½��ļ�·��(ע�⣺�ļ�·����ʽ������ "/***/***" �ĸ�ʽ)
		file_dir = explode(save_file_name, "/");
		file_dir_add = "";
		for ( i =0; i < sizeof(file_dir) - 1; i++ )
		{
			if ( file_dir[i] != "" )
				file_dir_add += ("/" + file_dir[i]);
			if ( file_dir_add != "" && file_dir_add != "/" )
				mkdir(file_dir_add);
		}

		if ( sscanf(file_arg, "%s###END***", file_arg) == 1 )
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg, 1);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �ɹ����յ��ļ�(" + save_file_name + ")��\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET �ɹ����յ��ļ�(" + save_file_name + ") On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			save_file_name = "/temp.c";
			all_file_arg = "";
		}
		else
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg, 1);
		}
	}
	else
	{
		if ( sscanf(mess, "%s###END***", file_arg) == 1 )
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �ɹ����յ��ļ�(" + save_file_name + ")��\n"NOR);
			log_file("/net/net_server", sprintf("���� SOCKET �ɹ����յ��ļ�(" + save_file_name + ") On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			save_file_name = "/temp.c";
			all_file_arg = "";
		}
		else
		{
			all_file_arg = mess;
			write_file(save_file_name, all_file_arg);
		}
	}

	return;
}

protected void server_close_callback(int fd)
{
	// �ر� SOCKET
	if ( server_socket )
		socket_close(server_socket);

	// 30������¿�ʼ����
	call_out("listen_server", 30);
	return;

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺼��� SOCKET �Ͽ����ӡ�\n"NOR);
	log_file("/net/net_server", sprintf("���� SOCKET �Ͽ����� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

void connect_to(string arg, string str)
{
	string file, pass;

	if ( sscanf(arg, "%s %d", to_addr, send_file_port) != 2 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ��������ӵ�Զ��λַ����\n"NOR);
		log_file("/net/net_server", sprintf("���ӵ�Զ��λַ���� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( sscanf(str, "%s#%s", file, pass) != 2 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺱��ܾ��������ʽ��\n"NOR);
		log_file("/net/net_server", sprintf("���ܾ��������ʽ On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺽���Զ�˵�ַ�С�\n"NOR);
	log_file("/net/net_server", sprintf("����Զ�˵�ַ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	send_file_name = file;
	send_file_arg = read_file(file);
	server_passwd = pass;
	resolve(to_addr, "file_resolve_callback");
}

void file_resolve_callback(string address, string resolved, int key)
{
	int ret;
	string full_addr;
	
	while (1)
	{
		if ( ! resolved )
		{
			if ( sscanf(to_addr, "%*d.%*d.%*d.%*d") == 4 )
				resolved = to_addr;
			else
			{
#ifdef FILE_SERVER_DEBUG
				CHANNEL_D->do_channel( this_object(), "sys", "�ļ������޷�����Զ�˵�ַ��\n"NOR);
				log_file("/net/net_server", sprintf("�޷�����Զ�˵�ַ On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
				break;
			}
		}
		
		full_addr = sprintf("%s %d", resolved, send_file_port);
		send_file_socket = socket_create(STREAM, "file_read_callback", "file_close_callback" );
		
		if ( send_file_socket < 0 )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ������ļ����� SOCKET ��ʼ��ʧ�ܡ�\n"NOR);
			log_file("/net/net_server", sprintf("�ļ����� SOCKET ��ʼ��ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			break;
		}
		
		ret = socket_connect(send_file_socket, full_addr, "file_read_callback", "file_write_callback");
		
		if (ret != EESUCCESS)
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ������������Ӵ���\n"NOR);
			log_file("/net/net_server", sprintf("�������Ӵ��� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			break;
		}
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ�������������" + address + "(" + full_addr + ")������\n"NOR);
		log_file("/net/net_server", sprintf("��������%s(%s) On %s��\n", address, full_addr, CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}
}

void file_read_callback(int fd, string mess)
{
	if (stringp(mess))
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺽��յ�Զ��Ӧ����Ϣ��\n"NOR);
		log_file("/net/net_server", sprintf("���յ�Զ��Ӧ����Ϣ On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}
}

void file_write_callback(int fd)
{
	send_to_remote();
}

void file_close_callback(int fd)
{
	// �ر� SOCKET
	if ( send_file_socket )
		socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ������ļ����� SOCKET �Ͽ����ӡ�\n"NOR);
	log_file("/net/net_server", sprintf("�ļ����� SOCKET �Ͽ����� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

private void send_to_remote()
{
	string msg;
	msg = "@@@" + send_file_name + "#@#" + server_passwd + "@@@##" + send_file_arg + "###END***";
	
	switch ( socket_write(send_file_socket, msg) )
	{
		// ���ͳɹ���
		case EESUCCESS:
			//call_out("file_close_callback", 0);
		case EECALLBACK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷����ļ�(" + send_file_name + ")�ɹ���\n"NOR);
			log_file("/net/net_server", sprintf("�����ļ�(" + send_file_name + ")�ɹ� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		
		// ������������
		case EEWOULDBLOCK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷����ļ���������������·��͡�\n"NOR);
			log_file("/net/net_server", sprintf("�����ļ���������������·��� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			call_out("send_to_remote", 3);
			return;
			
		default:
			// ����ʧ�ܣ��ر� SOCKET
			if ( send_file_socket )
				socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷����ļ�ʧ�ܡ�\n"NOR);
			log_file("/net/net_server", sprintf("�����ļ�ʧ�� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
			CHANNEL_D->do_channel( this_object(), "sys", "�ļ������ļ����� SOCKET �ѹرա�\n"NOR);
			log_file("/net/net_server", sprintf("�ļ����� SOCKET �ѹر� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
	}
}

// ��������
void remove(string euid)
{
	if ( send_file_socket )
		socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷�����ֹ���ļ����� SOCKET �رա�\n"NOR);
	log_file("/net/net_server", sprintf("������ֹ���ļ����� SOCKET �ر� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

	if ( server_socket )
		socket_close(server_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "�ļ����񣺷�����ֹ������ SOCKET �رա�\n"NOR);
	log_file("/net/net_server", sprintf("������ֹ������ SOCKET �ر� On %s��\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

	return;
}