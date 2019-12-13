// �ļ������� V-1.103 by Wenwu On 2007.09.10

//_____________________֧�ֹ�������___________________
// 1��֧����������
// 2��֧�ֵ����������ļ�����
// 3��֧�ִ������ⳤ��(��С)���ļ�
// 4���ͻ���֧�ֶ����������

// �������������Ϊ���ص���
#undef DEBUG

// �����˿�
#ifdef __SENSIBLE_MODIFIERS__
#define SV_PORT get_config(15)
#else
#define SV_PORT get_config(__MUD_PORT__)
#endif

// ��������
#define SERVER_PASS "Long12345"
// ÿ�ζ�ȡ���ļ�����
#define MAX_SIZE 30000
// �ϴ��ļ�����ÿ�ٷ�֮����ʾ�½���
#define RATE_SHOW 3
// �ļ����ȴ����������ʾ����
#define MAX_SHOW_RATE 100000

#include <net/socket.h>
#include <runtime_config.h>
#include <net/server.h>

inherit F_DBASE;

nosave private int vfd = -1; // ��������� SOCKET
nosave private mapping sv_info = ([ ]); // �������Ϣ
nosave private int cfd = -1; // �ͻ��� SOCKET
nosave private mapping cv_info = ([ ]); // �ͻ�����Ϣ
nosave private mapping temp_info = ([ ]); // ��ʱ�ݴ���Ϣ
nosave private string *cmd_buffer = ({ }); // �����ݴ�

//___________________���ⲿ���õĺ���_____________________
void connect_to(object ob, string arg);

//_____________________�ڲ����ú���_______________________
protected void sys_msg(string msg);
protected void log_msg(string msg);
protected void setup();
protected int send_to_remote(int fd, mixed mess, int flag);
protected void send_message(int fd, int flag);
protected void send_dir(int fd, string dir);
protected int get_file(int fd, string dir, int type);
private void remove_temp(string address, int fd);
private void heart_beat();
void remove();
//_____________________�����ͨѶ����_____________________
protected void in_read_callback(int fd, mixed mess);
protected void in_write_callback(int fd, mixed mess);
protected void in_close_callback(int fd);
//_____________________�ͻ���ͨѶ����_____________________
protected void send_read_callback(int fd, mixed mess);
protected void send_write_callback(int fd, mixed mess);
protected void send_close_callback(int fd);

void create()
{
	seteuid(getuid());
	set("channel_id", "�汾����");
	sys_msg("�汾�����Ѿ�������"NOR);
	set_heart_beat(1);
	setup(); // ��ʼ��
}

protected void setup()
{
	// �������� socket
	vfd = socket_create(STREAM_BINARY, "in_read_callback", "in_close_callback" );

	if ( vfd < 0 )
	{ // ʧ��
		sys_msg("�������� socket ʧ��");
		log_msg("�������� socket ʧ��");
		return;
	}
	if ( socket_bind(vfd, SV_PORT) < 0 )
	{ // �󶨶˿�ʧ��
		sys_msg("���� socket �󶨶˿�ʧ��");
		log_msg("���� socket �󶨶˿�ʧ��");
		socket_close(vfd);
		return;
	}
	if ( socket_listen(vfd, "in_listen_callback" ) < 0 )
	{ // ����ʧ��
		sys_msg("����ʧ��");
		log_msg("����ʧ��");
		socket_close(vfd);
		return;
	}

	sv_info = ([ ]); // ��ʼ��
	sys_msg("��ʼ�ڶ˿� "+SV_PORT+" ������");
}

protected void in_listen_callback(int fd)
{
	int new_fd;

	if ( (new_fd = socket_accept(fd, "in_read_callback", "in_write_callback")) < 0 ) 
	{ // ��������ʧ��
		sys_msg("��������ʧ��");
		log_msg("��������ʧ��");
		in_close_callback(new_fd);
		return;
	}

	sv_info[new_fd] = ([ ]); // ��ʼ��
	sv_info[new_fd][STATE] = WAIT; // ���ڵȴ������ļ�״̬
}

protected void in_read_callback(int fd, mixed mess)
{
	string show, pass, file_name, msg;
	string send, get_dir, *fname_list;
	int i, file_size, type;
	
	// ����ʼ������
	if ( !mapp(sv_info) ) sv_info = ([ ]);
	if ( !mapp(sv_info[fd]) ) sv_info[fd] = ([ ]);
	if ( !arrayp(sv_info[fd][WAIT_FILE]) ) sv_info[fd][WAIT_FILE] = ({ });
	
	if ( stringp(mess) ) msg = mess;
	else if ( bufferp(mess) ) msg = read_buffer(mess, 0, (sizeof(mess)));
	else 
	{ // �����ϵ���������
		sys_msg("���յ��������ʹ���");
		log_msg("���յ��������ʹ���");
		return;
	}

	if ( sscanf(msg, VALID_CHECK, show, pass, file_name, file_size, type) == 5 )
	{ // ��֤
		if ( pass != SERVER_PASS )
		{ // ��֤����
			sys_msg("����������֤ʧ��");
			log_msg("����������֤ʧ��");
			return;
		}
		if ( type == FINISH )
		{ // �յ�����ȫ����ɵ���Ϣ
			sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" "+show);
			// �ر��׽���
			in_close_callback(fd);
			return;
		}
		if ( type == CMD )
		{ // �յ�ָ��
			send = sprintf(REPLY_MESSAGE, FILE, file_name);
			sv_info[fd][WAIT_FILE] += ({ send });
			send_message(fd, SFLAG);
			return;
		}
		//____________________________����Ŀ¼_______________________
#ifdef DEBUG
		file_name = "/temp"+file_name;
#endif
		if ( file_name[0..0] != "/" ) file_name = "/" + file_name;
		
		get_dir = "/";
		fname_list = explode(file_name, "/");
		for ( i=0; i<sizeof(fname_list)-1; i++ )
		{
			get_dir += fname_list[i];
			mkdir(get_dir);
			get_dir += "/";
		}
		//____________________________�������________________________
		//______________________��MUD�����õ��ļ�___________________
		/* �����ֱ������ BINARY �ķ�վ����ô��д�� .b �ļ�ǰ����������
		   ԭ�����ļ�����Ȼ����ļ�û����ȫд��ʱ���ö�������ļ����ܻ�
		   �����ڴ���������� */
		/*name_size = sizeof(file_name);
		if ( file_name[(name_size-2)..(name_size-1)] == ".b" )
		{
			if ( err = catch(call_other(replace_string(file_name[0..<3], "/binaries/", "/"), "???")) )
				sys_msg(HIR"��������"NOR+err);
		}*/
		//_____________________________ END __________________________
		if ( !write_file(file_name, "", 1) )
		{ // ɾ��ԭ�����ļ�
			sys_msg("ɾ���ɵ��ļ�("+file_name+")ʧ��");
			log_msg("ɾ���ɵ��ļ�("+file_name+")ʧ��");
			return;
		}
		// Ӧ����Ϣ�б�
		// �ǿ��ļ�
		if ( file_size == 0 )
		{ // ֪ͨ������һ���ļ�
			sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" "+show);
			sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" �����ļ� "HIG+file_name+HIW" ("HIY+file_size+"�ֽ�"HIW")");
			send = sprintf(REPLY_MESSAGE, FINISH, file_name);
			if ( member_array(send, sv_info[fd][WAIT_FILE]) == -1 ) 
				sv_info[fd][WAIT_FILE] += ({ send });
			send_message(fd, SFLAG);
			sv_info[fd][STATE] = FINISH;
			sv_info[fd][VALID] = 0;
			sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" ������� "HIG+file_name+HIW" ("HIY+file_size+"�ֽ�"HIW")");
			return;
		}
		if ( sv_info[fd][STATE] == DOING && file_name != sv_info[fd][FILE_NAME] )
		{ // ��һ���ļ���û�з����꣬�޷������µ��ļ�����֪�Է��Ժ���
			send = sprintf(REPLY_MESSAGE, RESET_SEND, file_name);
			if ( member_array(send, sv_info[fd][WAIT_FILE]) == -1 ) 
				sv_info[fd][WAIT_FILE] += ({ send });
			send_message(fd, SFLAG);
			return;
		}
		sv_info[fd][FILE_NAME] = file_name;
		sv_info[fd][FILE_SIZE] = file_size;
		sv_info[fd][TYPE] = type;
		sv_info[fd][BUFFER] = "";
		sv_info[fd][VALID] = 1;
		sv_info[fd][FILE_POS] = 0;
		sv_info[fd][STATE] = DOING;
		sv_info[fd][RATE] = 0;
		sv_info[fd][SHOW] = BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" "+show;

		// ��֤ͨ��������һ����Ϣ֪ͨ�����ļ�
		send = sprintf(REPLY_MESSAGE, VALID_SEND, file_name);
		if ( member_array(send, sv_info[fd][WAIT_FILE]) == -1 ) 
			sv_info[fd][WAIT_FILE] += ({ send });
		send_message(fd, SFLAG);
		if ( sv_info[fd][FILE_SIZE] > MAX_SHOW_RATE )
			sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" �����ļ� "HIG+sv_info[fd][FILE_NAME]+HIW" ("HIY+sv_info[fd][FILE_SIZE]+"�ֽ�"HIW")");
		return;
	}

	if ( sv_info[fd][VALID] )
	{
		sv_info[fd][FILE_POS] += sizeof(mess);
		sv_info[fd][RATE] += sizeof(mess);
		sv_info[fd][BUFFER] = msg;
		
		if ( sv_info[fd][FILE_NAME] )
		{
			// д���ļ�
			if ( sv_info[fd][TYPE] == ASCII )
			{ // ASCII �ļ�
				sv_info[fd][BUFFER] = replace_string(sv_info[fd][BUFFER], "\r", "");
				if ( write_file(sv_info[fd][FILE_NAME], sv_info[fd][BUFFER]) )
				{
					if ( sv_info[fd][FILE_SIZE] > MAX_SHOW_RATE )
					{ // �Ƚϴ���ļ���ʾ����
						if ( sv_info[fd][RATE]/(sv_info[fd][FILE_SIZE]/100) >= RATE_SHOW )
						{
							sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" ���ս��� "HIY+sv_info[fd][FILE_POS]+" �ֽ� "HIW"("HIG+(sv_info[fd][FILE_POS]*10/(sv_info[fd][FILE_SIZE]/10))+"%"HIW")");
							sv_info[fd][RATE] = 0;
						}
					}
				}
				else
				{
					log_msg("д�� ASCII �ļ�("+sv_info[fd][FILE_NAME]+")ʧ��");
					sv_info[fd][VALID] = 0;
					return;
				}
			}
			else if ( sv_info[fd][TYPE] == BINARY ) 
			{ // BINARY �ļ�
				if ( write_buffer(sv_info[fd][FILE_NAME], file_size(sv_info[fd][FILE_NAME]), mess) )
				{
					if ( sv_info[fd][FILE_SIZE] > MAX_SHOW_RATE )
					{ // �Ƚϴ���ļ���ʾ����
						if ( sv_info[fd][RATE]/(sv_info[fd][FILE_SIZE]/100) >= RATE_SHOW )
						{
							sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" ���ս��� "HIY+sv_info[fd][FILE_POS]+" �ֽ� "HIW"("HIG+(sv_info[fd][FILE_POS]*10/(sv_info[fd][FILE_SIZE]/10))+"%"HIW")");
							sv_info[fd][RATE] = 0;
						}
					}
				}
				else
				{
					log_msg("д�� BINARY �ļ�("+sv_info[fd][FILE_NAME]+")ʧ��");
					sv_info[fd][VALID] = 0;
					return;
				}
			}
			//_____________________���ò�����____________________
			if ( sv_info[fd][FILE_POS] == sv_info[fd][FILE_SIZE] )
			{ // �������
				if ( sv_info[fd][FILE_SIZE] > MAX_SHOW_RATE )
					sys_msg(BBLU+HIR"[ "HIG+fd+HIR" ]"NOR+HIW" ���ս��� "HIY+sv_info[fd][FILE_POS]+" �ֽ� "HIW"("HIG+(sv_info[fd][FILE_POS]*10/(sv_info[fd][FILE_SIZE]/10))+"%"HIW")");
				sv_info[fd][FILE_NAME] = 0;
				sv_info[fd][FILE_SIZE] = 0;
				sv_info[fd][TYPE] = 0;
				sv_info[fd][BUFFER] = "";
				sv_info[fd][FILE_POS] = 0;
				sv_info[fd][VALID] = 0;
				sv_info[fd][STATE] = FINISH;
				sv_info[fd][RATE] = 0;
				// ����ļ�������ϣ�������Ϣ֪ͨ������һ���ļ�
				send = sprintf(REPLY_MESSAGE, FINISH, file_name);
				if ( member_array(send, sv_info[fd][WAIT_FILE]) == -1 ) 
					sv_info[fd][WAIT_FILE] += ({ send });
				send_message(fd, SFLAG);
				sys_msg(sv_info[fd][SHOW]); // ��ʾ����
			}
			else if ( sv_info[fd][FILE_POS] > sv_info[fd][FILE_SIZE] )
			{ // �ļ����Ȳ��ԣ�Ҫ�����·���
				send = sprintf(REPLY_MESSAGE, RESET_SEND, sv_info[fd][FILE_NAME]);
				if ( member_array(send, sv_info[fd][WAIT_FILE]) == -1 ) 
					sv_info[fd][WAIT_FILE] += ({ send });
				send_message(fd, SFLAG);
				// ���ò���
				sv_info[fd][FILE_NAME] = 0;
				sv_info[fd][FILE_SIZE] = 0;
				sv_info[fd][TYPE] = 0;
				sv_info[fd][BUFFER] = "";
				sv_info[fd][FILE_POS] = 0;
				sv_info[fd][VALID] = 0;
				sv_info[fd][STATE] = FINISH;
				sv_info[fd][RATE] = 0;
			}
			//______________________�������_____________________
		}
		return;
	}

	sys_msg("�Ƿ�����");
	// ��ʾ��Ϣ
	send = HIW"\n"HBRED"����ͬ��������. . .\n"HIY"���Ժ��������� �� ʹ�������˿����µ�¼��лл������"NOR"\n";
	sv_info[fd][WAIT_FILE] += ({ send });
	send_message(fd, SFLAG);
}

protected void in_write_callback(int fd, mixed mess)
{
	sys_msg("������Ӧ��");
}

protected void in_close_callback(int fd)
{
	if ( fd > -1 ) 
	{
		socket_close(fd);
		sys_msg("������׽���( "+fd+" )�Ͽ�����");
	}

	map_delete(sv_info, fd);
}

// ������Ϣ
protected void sys_msg(string msg)
{
	message("wiz", HIR"�汾����"HIW+msg+"\n"NOR, users());
}

// ��¼
protected void log_msg(string msg)
{
	log_file("/net/server", sprintf("%s��%s\n", CHINESE_D->chinese_time(7, time()), msg));
}

void connect_to(object ob, string arg)
{
	string ip, file_name, pass;
	int port, name_size;

	if ( sscanf(arg, "%s %d,%s,%s", ip, port, file_name, pass) == 4 )
	{ // ��������ʽ
		if ( !mapp(temp_info) ) temp_info = ([ ]);
		if ( sizeof(temp_info) )
		{ // ����δ�����Ϣ
			if ( !arrayp(cmd_buffer) ) cmd_buffer = ({ });
			if ( member_array(arg, cmd_buffer) == -1 ) cmd_buffer += ({ arg });
			if ( objectp(ob) ) tell_object(ob, "ϵͳ��æ�������ݴ��뻺�����ȴ����͡�\n");
			return;
		}

		name_size = strlen(file_name) - 1;

		if ( file_name[name_size..name_size] == "/" )
		{ // ��Ŀ¼
			if ( file_size(file_name[0..(name_size-1)]) != -2 )
			{ // û�����Ŀ¼
				if ( objectp(ob) ) tell_object(ob, "Ŀ¼("+file_name+")�����ڡ�\n");
				return;
			}
		}
		else if ( file_size(file_name) < 0 )
		{ // ���͵��ļ�������
			if ( objectp(ob) ) tell_object(ob, "�ļ�("+file_name+")�����ڡ�\n");
			return;
		}

		//______________________________��ʼ������___________________________
		temp_info[IP] = ip;
		temp_info[PORT] = port;
		temp_info[FILE_NAME] = file_name;
		temp_info[PASS] = pass;
		temp_info[BUFFER] = sprintf(VALID_CHECK, pass, file_name, 0, CMD);
	}
	else
	{
		if ( objectp(ob) ) tell_object(ob, "�����ʽ����\n");
		return;
	}
	
	sys_msg("�������ӷ�����("+temp_info[IP]+" "+temp_info[PORT]+")�����Ժ�...");
	resolve(temp_info[IP], "resolve_callback");
}

protected void resolve_callback(string address, string resolved, int key)
{
	string full_addr;
	int ret;
	
	if ( !resolved )
	{ // ��������ʧ��
		if ( sscanf(temp_info[IP], "%*d.%*d.%*d.%*d") == 4 )
			resolved = temp_info[IP];
		else
		{
			sys_msg("����("+temp_info[IP]+")����ʧ��");
			temp_info = ([ ]); // ��ղ���
			return;
		}
	} 
	else if ( resolved != temp_info[IP] )
		sys_msg("�������� "+temp_info[IP]+" = "+resolved);
	
	full_addr = sprintf("%s %d", resolved, temp_info[PORT]);
	cfd = socket_create(STREAM_BINARY, "send_read_callback", "send_close_callback" );
		
	if ( cfd < 0 )
	{
		sys_msg("�����ͻ��� socket ʧ��");
		log_msg("�����ͻ��� socket ʧ��");
		temp_info = ([ ]); // ��ղ���
		return;
	}
		
	ret = socket_connect(cfd, full_addr, "send_read_callback", "send_write_callback");
		
	if ( ret != EESUCCESS )
	{
		sys_msg("�޷����ӷ�����("+full_addr+")");
		log_msg("�޷����ӷ�����("+full_addr+")");
		temp_info = ([ ]); // ��ղ���
		send_close_callback(cfd); // ������Դ
		return;
	}

	//______________________________��ʼ������___________________________
	if ( !mapp(cv_info) ) cv_info = ([ ]);
	cv_info[cfd] = ([ ]);
	cv_info[cfd][WAIT_POT] = ({ });
	cv_info[cfd][WAIT_FILE] = ({ });
	cv_info[cfd][DOMAIN] = temp_info[IP];
	cv_info[cfd][IP] = resolved;
	cv_info[cfd][PORT] = temp_info[PORT];
	cv_info[cfd][FILE_NAME] = temp_info[FILE_NAME];
	cv_info[cfd][FILE_SIZE] = 0;
	cv_info[cfd][PASS] = temp_info[PASS];
	cv_info[cfd][TYPE] = BINARY;
	cv_info[cfd][MAX_FILE] = 0;
	cv_info[cfd][FINISH_FILE] = 0;
	cv_info[cfd][VALID] = 0;
	cv_info[cfd][RATE] = 0;
	cv_info[cfd][FILE_POS] = 0;
	cv_info[cfd][BUFFER] = "";
	cv_info[cfd][VALID] = 0;
	cv_info[cfd][FINISH] = 0;

	call_out("remove_temp", 30, full_addr, cfd);
}

protected void send_read_callback(int fd, mixed mess)
{
	string msg, filename, show;
	int i, max, type, filesize, rate, name_size;
	mixed send;
	
	if ( stringp(mess) ) msg = mess;
	else if ( bufferp(mess) ) msg = read_buffer(mess, 0, (sizeof(mess)));
	else return;

#ifdef DEBUG
	msg = replace_string(msg, "/temp/", "/");
#endif

	if ( sscanf(msg, REPLY_MESSAGE, type, filename) == 2 )
	{
		switch ( type )
		{
			// ��ʼ�����ļ�
			case VALID_SEND :
				if ( (filesize=file_size(filename)) < 0 ) 
				{ // �ļ�������
					sys_msg("�ļ�("+filename+")������");
					return;
				}
				if ( !arrayp(cv_info[fd][WAIT_POT]) ) cv_info[fd][WAIT_POT] = ({ });
				if ( filesize < MAX_SIZE )
				{
					send = read_buffer(filename);
					cv_info[fd][WAIT_POT] += ({ send });
				}
				else
				{
					rate = 0;
					do
					{
						send = read_buffer(filename, rate, MAX_SIZE);
						cv_info[fd][WAIT_POT] += ({ send });
						rate += MAX_SIZE;
					}
					while ( rate < filesize );
				}
				
				if ( filesize > MAX_SHOW_RATE )
					sys_msg(BRED+HIB"[ "HIW+fd+HIB" ]"NOR+HIW" �����ļ� "HIC+filename+HIW" ("HIY+filesize+"�ֽ�"HIW")");

				send_message(fd, CFLAG);
				return;
			// δ�ɹ����յ����ļ�������еȴ��´η���
			case RESET_SEND :
				if ( (filesize=file_size(filename)) < 0 ) 
				{ // �ļ�������
					sys_msg("�ļ�("+filename+")������");
					return;
				}
				if ( !arrayp(cv_info[fd][WAIT_FILE]) ) cv_info[fd][WAIT_FILE] = ({ });
				if ( member_array(filename, cv_info[fd][WAIT_FILE]) == -1 ) 
					cv_info[fd][WAIT_FILE] += ({ filename });
				// ��������ֹͣ�˷��ͣ����������δ�ɹ���ɵ�
				cv_info[fd][WAIT_POT] -= ({ 0 });
				if ( !(sizeof(cv_info[fd][WAIT_POT])) && cv_info[fd][FINISH] ) 
					send_read_callback(fd, sprintf(REPLY_MESSAGE, FINISH, "reset"));
				return;
			// �ϸ��ļ��ѳɹ����ͣ����������¸��ļ�
			case FINISH :
				if ( filename != "reset" ) cv_info[fd][FINISH_FILE]++;
				if ( cv_info[fd][FINISH_FILE] <= cv_info[fd][MAX_FILE] )
				{
					show = "��ɶ�("HIY+(cv_info[fd][FINISH_FILE]*100/cv_info[fd][MAX_FILE])+"%"+HIW")��"HIG + 
						cv_info[fd][FINISH_FILE]+HIY" / "HIC+cv_info[fd][MAX_FILE];
					sys_msg(BRED+HIB"[ "HIW+fd+HIB" ]"NOR+HIW" "+show);
					if ( cv_info[fd][FINISH_FILE] == cv_info[fd][MAX_FILE] )
					{ // ȫ��������ɣ�����һ����Ϣ֪ͨ
						send = sprintf(VALID_CHECK, show, cv_info[fd][PASS], "out", 0, FINISH);
						cv_info[fd][WAIT_POT] += ({ send });
						send_message(fd, CFLAG);
						cv_info[fd][FINISH] = 1; // ��־ȫ�����

						if ( !mapp(cv_info[fd]) ) cv_info[fd] = ([ ]);
						if ( !arrayp(cv_info[fd][WAIT_FILE]) ) cv_info[fd][WAIT_FILE] = ({ });

						cv_info[fd][WAIT_FILE] -= ({ 0 });

						if ( sizeof(cv_info[fd][WAIT_FILE]) && filename != "reset" ) 
						{
							sys_msg(HIR"�������󣬻����������ļ�δ�ɹ�����");
							log_msg("�������󣬻����������ļ�δ�ɹ�����");
						}
						return;
					}
				}

				if ( !mapp(cv_info[fd]) ) 
				{
					send_close_callback(fd);
					return;
				}
				if ( !arrayp(cv_info[fd][WAIT_FILE]) )
				{
					send_close_callback(fd);
					return;
				}

				cv_info[fd][WAIT_FILE] -= ({ 0 });

				if ( !(max=sizeof(cv_info[fd][WAIT_FILE])) )
				{
					send_close_callback(fd);
					return;
				}
				
				for ( i=0; i<max; i++ )
				{
					send = cv_info[fd][WAIT_FILE][i];

					if ( !stringp(send) && !bufferp(send) )
					{ // ��Ч���ļ���
						cv_info[fd][WAIT_FILE][i] = 0;
						continue;
					}
					if ( (filesize=file_size(send)) < 0 )
					{ // û������ļ�
						cv_info[fd][WAIT_FILE][i] = 0;
						continue;
					}
					//____________________����״̬��Ϣ__________________
					cv_info[fd][FILE_NAME] = send;
					cv_info[fd][FILE_SIZE] = filesize;
					cv_info[fd][TYPE] = BINARY;
					show = "��ɶ�("HIY+(cv_info[fd][FINISH_FILE]*100/cv_info[fd][MAX_FILE])+"%"+HIW")��"HIG + 
						cv_info[fd][FINISH_FILE]+HIY" / "HIC+cv_info[fd][MAX_FILE];
					cv_info[fd][BUFFER] = sprintf(VALID_CHECK, show, cv_info[fd][PASS], send, filesize, cv_info[fd][TYPE]);
					//_____________________������Ϣ_____________________
					cv_info[fd][WAIT_POT] += ({ cv_info[fd][BUFFER] });
					cv_info[fd][WAIT_FILE][i] = 0;
					break;
				}
				send_message(fd, CFLAG);
				return;
			// �յ����ļ�������
			case FILE :
				name_size = strlen(filename)-1;

				if ( filename[name_size..name_size] == "/" )
				{ // ��Ŀ¼
					send_dir(fd, filename);
					return;
				}
				if ( file_size(filename) < 0 )
				{ // ���͵��ļ�������
					sys_msg("Ҫ���͵��ļ�("+filename+")������");
					send_close_callback(fd);
					return;
				}

				cv_info[fd][MAX_FILE] = 1;
				cv_info[fd][FINISH_FILE] = 0;
				cv_info[fd][WAIT_FILE] += ({ filename });

				// ��ʼ�����ļ�
				send_read_callback(fd, sprintf(REPLY_MESSAGE, FINISH, "reset"));
				return;
			// ����
			default:
				return;
		}
	} 
	else if ( sscanf(msg, SHOW_MESSAGE, type, filename) == 2 )
	{
		switch ( type )
		{
			// ״̬��ʾ��Ϣ
			case SHOW_SEND :
				sys_msg(filename);
				return;
			// ����
			default:
				return;
		}
	}

	sys_msg(msg);
}

protected void send_write_callback(int fd, mixed mess)
{
	sys_msg("���ӳɹ�");
	cv_info[fd][VALID] = 1;
	send_to_remote(fd, temp_info[BUFFER], TFLAG);
	temp_info = ([ ]); // ��ղ���
	remove_call_out("remove_temp");
}

protected void send_close_callback(int fd)
{
	if ( fd > -1 ) 
	{
		socket_close(fd);
		sys_msg("�ͻ����׽���( "+fd+" )�Ͽ�����");
	}

	map_delete(cv_info, fd);
}

protected int send_to_remote(int fd, mixed mess, int flag)
{	
	switch ( socket_write(fd, mess) )
	{
		// ���ͳɹ���
		case EESUCCESS:
		case EECALLBACK:
			return 1;
		// ������������
		case EEWOULDBLOCK:
			if ( flag == TFLAG )
				call_out("send_to_remote", 0, fd, mess, flag);
			return 0;
		default:
			// ���͹����г��ִ���
			return -1;
	}
}

protected void send_message(int fd, int flag)
{
	mixed send;
	int i, max, type;

	switch ( flag )
	{
		// �ͻ��˴���
		case CFLAG :
			if ( !mapp(cv_info) ) return;
			if ( !mapp(cv_info[fd]) ) return;
			if ( !arrayp(cv_info[fd][WAIT_POT]) ) return;

			cv_info[fd][WAIT_POT] -= ({ 0 });

			if ( !(max=sizeof(cv_info[fd][WAIT_POT])) ) return;
			
			for ( i=0; i<max; i++ )
			{
				send = cv_info[fd][WAIT_POT][i];

				if ( !stringp(send) && !bufferp(send) )
				{ // δ֪��������
					cv_info[fd][WAIT_POT][i] = 0;
					continue;
				}
				if ( !(type=send_to_remote(fd, send, flag)) )
				{ // ��Ϣ���������·���
					call_out("send_message", 0, fd, flag);
					return;
				}
				if ( type == -1 ) 
				{
					sys_msg(HIY"���͹����г��ִ���");
					send_close_callback(fd);
					return;
				}
				if ( bufferp(cv_info[fd][WAIT_POT][i]) 
					&& cv_info[fd][FILE_SIZE] > MAX_SHOW_RATE )
				{ // �ϴ��ļ���ʾ���ͽ���
					cv_info[fd][FILE_POS] += sizeof(cv_info[fd][WAIT_POT][i]);
					cv_info[fd][RATE] += sizeof(cv_info[fd][WAIT_POT][i]);
					if ( cv_info[fd][RATE]/(cv_info[fd][FILE_SIZE]/100) > RATE_SHOW 
						|| cv_info[fd][FILE_POS] == cv_info[fd][FILE_SIZE] )
					{
						cv_info[fd][RATE] = 0;
						sys_msg(BRED+HIB"[ "HIW+fd+HIB" ]"NOR+HIW" ���ͽ��� "HIG+cv_info[fd][FILE_POS]+" �ֽ� "HIW"("HIM+(cv_info[fd][FILE_POS]*10/(cv_info[fd][FILE_SIZE]/10))+"%"HIW")");
					}
				}
				else
				{ // �����ļ����ݣ����÷��ͽ��Ȳ���
					cv_info[fd][RATE] = 0;
					cv_info[fd][FILE_POS] = 0;
				}

				cv_info[fd][WAIT_POT][i] = 0;
				break;
			}

			send_message(fd, flag);
			return;
		// ����˴���
		case SFLAG :			
			if ( !mapp(sv_info) ) return;
			if ( !mapp(sv_info[fd]) ) return;
			if ( !arrayp(sv_info[fd][WAIT_FILE]) ) return;

			sv_info[fd][WAIT_FILE] -= ({ 0 });

			if ( !(max=sizeof(sv_info[fd][WAIT_FILE])) ) return;
			
			for ( i=0; i<max; i++ )
			{
				send = sv_info[fd][WAIT_FILE][i];

				if ( !stringp(send) && !bufferp(send) )
				{ // δ֪��������
					sv_info[fd][WAIT_FILE][i] = 0;
					continue;
				}
				if ( !(type=send_to_remote(fd, send, flag)) )
				{ // ��Ϣ���������·���
					call_out("send_message", 0, fd, flag);
					return;
				}
				if ( type == -1 ) 
				{
					sys_msg(HIY"���͹����г��ִ���");
					in_close_callback(fd);
					return;
				}

				sv_info[fd][WAIT_FILE][i] = 0;
				break;
			}

			send_message(fd, flag);
			return;
		// ����
		default:
	}
}

protected void send_dir(int fd, string dir)
{
	int max;

	if ( !get_file(fd, dir, 1) ) 
	{ // û���ļ�
		send_close_callback(fd);
		return;
	}

	cv_info[fd][WAIT_FILE] -= ({ 0 });

	if ( !(max = sizeof(cv_info[fd][WAIT_FILE])) )
	{
		sys_msg("Ŀ¼("HIY+dir+HIW")��û���κ��ļ�");
		send_close_callback(fd);
		return;
	}

	cv_info[fd][MAX_FILE] = max;
	cv_info[fd][FINISH_FILE] = 0;
	
	// ��ʼ�����ļ�
	send_read_callback(fd, sprintf(REPLY_MESSAGE, FINISH, "reset"));
}

protected int get_file(int fd, string dir, int type)
{
	mixed *file;
	int i, j;
	
	// ȡ��Ŀ¼���ļ�
	file = get_dir(dir, -1);
	
	if ( type )
	{
		if ( !sizeof(file) )
		{ // û���ļ�
			if ( file_size(dir) == -2 ) sys_msg("Ŀ¼("HIY+dir+HIW")�ǿյ�");
			else sys_msg("û�����Ŀ¼("HIY+dir+HIW")");
			return 0;
		}
	}

	i = sizeof(file);
	while ( i-- ) 
	{ // ����Ŀ¼
		if ( file[i][1] == -2 ) file[i][0] += "/";
	}
	
	sys_msg(HIG"����Ŀ¼��" + dir);

	if ( sizeof(file) )
	{
		for ( i=0, j = sizeof(file); i<j; i++ )
		{
			if ( file[i][1] > -1 ) 
			{
				cv_info[fd][WAIT_FILE] += ({ (dir+file[i][0]) });
				sys_msg(NOR"�����ļ���" + dir+file[i][0]);
			}
			else if ( file[i][1] == -2 ) 
				call_other(__FILE__, "get_file", fd, dir+file[i][0], 0);
		}
	}
	else
		sys_msg(HIY"û���κε���");

	return 1;
}

// ��������
void remove()
{
	int i, *fd;
	
	if ( mapp(sv_info) )
	{ // ��������������Ϣ
		fd = keys(sv_info);
		for ( i=0; i<sizeof(fd); i++ )
		{
			in_close_callback(fd[i]);
		}
	}

	if ( mapp(cv_info) )
	{ // ����ͻ���������Ϣ
		fd = keys(cv_info);
		for ( i=0; i<sizeof(fd); i++ )
		{
			send_close_callback(fd[i]);
		}
	}

	in_close_callback(vfd);
}

private void remove_temp(string address, int fd)
{
	if ( !mapp(cv_info) 
		|| !mapp(cv_info[fd]) 
		|| cv_info[fd][VALID] ) 
		return;

	sys_msg("�޷����ӵ�������("+address+")");
	temp_info = ([ ]); // ��ղ���
	send_close_callback(fd);
}

private void heart_beat()
{ // ִ�еȴ��е�����
	string cmd;
	int i, max;

	if ( !arrayp(cmd_buffer) ) cmd_buffer = ({ });

	cmd_buffer -= ({ 0 });

	if ( !(max = sizeof(cmd_buffer)) ) return;

	for ( i=0; i<max; i++ )
	{
		if ( !stringp(cmd=cmd_buffer[i]) )
		{ // �����ִ�
			cmd_buffer[i] = 0;
			continue;
		}
		
		cmd_buffer[i] = 0;
		connect_to(0, cmd);
		return;
	}
}

mapping get_info1()
{
	return sv_info;
}

mapping get_info2()
{
	return cv_info;
}

mapping get_info3()
{
	return temp_info;
}