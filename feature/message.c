// message.c

#include <dbase.h>
#include <liebiao.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});

void write_prompt();

void receive_message(string msgclass, string msg)
{
	object me;
	string subclass, *ch, huiyuan, year, mon, day, file_str, *chufa_list, chufa_msg, chufa_cmds;
	int len, v, i, prop;

	me = this_object();

	if(!msg || (len=strlen(msg))<1)
		return;

	if(len>8000)
		msg=msg[0..8000]+"\n\n������\n";

	prop = -1;

	if ( interactive(me) )
		prop = 1;
	else if ( playerp(me) && me->query("lixian/biguan") )
		prop = 0;

	if ( prop == -1 )
	{
		me->relay_message(msgclass, msg);
		return;
	}
	// ʹ��BIG5��
	//if ( query_ip_port(me) == BIG5_PORT )
	//	msg = efun::gbtobig5(msg);

	if ( prop == 1 )
	{
		// Զ�̵�½
		if ( msgclass == "telnet" )
		{
			receive(msg);
			return;
		}
		// ��ʦ��Ϣ
		if ( msgclass == "wiz" )
		{
			if ( !wizardp(me) ) return;
			if ( me->query("env/block_wiz_msg") ) return;
			receive(msg);
			return;
		}
		// �����Ϣ
		if ( msgclass == "party" )
		{
			if ( !living(me) ) return;
			if ( !me->query("xieyi/zmud") )
			{
				msg = replace_string(msg,BLINK,"");
				msg = PTEXT(msg);
			}
			receive(msg);
			return;
		}
		if ( msgclass == "notify_fail" )
		{
                 efun::notify_fail(ESC "[256D" ESC "[K" + msg);
			return;
		}
		// ������Ϣ
		if ( msgclass == "go" && me->query("env/block_go_msg") ) return;
		// ����Ƶ��
		if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 )
		{
			switch(subclass)
			{
				case "channel":
					if( !pointerp(ch = query("channels")) || member_array(msgclass, ch)==-1 )
					return;

					if ( !me->query("xieyi/zmud") )
					{
						if ( sscanf(msg,"%*s������ɭ�֡�%*s") || sscanf(msg,"%*s������ˮ�¡�%*s")
							|| sscanf(msg,"%*s���ĳ���Ϣ��%*s") || sscanf(msg,"%*s��ϵͳ���顿%*s")
							|| sscanf(msg,"%*s��[1;31m����׷ɱ��[1;34m��%*s") || sscanf(msg,"%*s��[1;33m����������[1;34m��%*s") )
						{
							if ( !sscanf(msg,"%*sptext%*s") )
								msg = PTEXT(msg);
						}
						//���˾ɰ汾Tomud�޷����͵�ANSI�ַ���
						if ( sscanf(msg,"%*sptext%*s") )
							msg = replace_string(msg,BLINK,"");
					}

					//���ӻ��Ի�˯��״̬�ɽ���������Ϣ
					if( !living(me) && prop == 1 )
					{
						receive( msg );
						return;
					}
					break;

				case "outdoor":
					if( !environment() || !environment()->query("outdoors") )
					return;

				case "room":
					if( !environment() || environment()->query("outdoors") )
					return;

				default:
					error("Message: Invalid Subclass " + subclass + ".\n");
			}
		}

		if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) ) return;

		if ( prop == 1 )
		{
			/*if( in_input(me) || in_edit(me) )
			{
				if ( !wizardp(me) && query_idle(me) > 300 && !objectp(me->query_temp("query_shadowed")) )
				{
					//remove_input_to(me);
					//tell_object(me, HIY"\n���������ַ�����ʱ�䳬��"HIC" �� "HIY"�����ˣ��������������˵�ɡ�\n"NOR);
					write_prompt();
				} else if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
					msg_buffer += ({ msg });
			}*/
			if( in_input(me) || in_edit(me) ){
                if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
                 msg_buffer += ({ msg });
                }
			else
				receive( msg );
		}
	}

	if ( prop ) return;

	// ����
	// --------------------------------------------------------------------
	// �����ǹرյ�
	if ( me->query("xyzx_chufa_stop") )
		return;

	// ��δ��ɵĴ�������ͣ�����ȴ�
	if ( me->query_temp("xyzx_sys_chufa") )
		return;

	// ���ǻ�Ա����ʹ�ô���
	if ( !me->query("xy_huiyuan") )
		return;

	if ( !stringp(huiyuan = me->query("xy_huiyuan")) )
		return;

	if ( sscanf(huiyuan, "%d��%d��%d��", year, mon, day) != 3 )
		return;

	// �������
	if ( !playerp(me) )
		return;

	// ��鴥�������ļ�
	if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) < 0 )
		return;

	file_str = read_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
	chufa_list = explode(file_str, "\n");
	v = sizeof(chufa_list);

	if ( v > CHUFA_CMD_SIZE )
		v = CHUFA_CMD_SIZE;

	// ȥ�� ANSI �ַ���
//	msg = efun::remove_ansi(msg);

	for ( i = 0; i < v; i++ )
	{
		if ( sscanf(chufa_list[i], "%s:%s", chufa_msg, chufa_cmds) == 2 && stringp(chufa_msg) && 0 < strlen(chufa_msg) )
		if ( sscanf(chufa_list[i], "%s:%s", chufa_msg, chufa_cmds) == 2 )
		{
			if ( strlen(msg) >= strlen(chufa_msg) && sscanf(msg, "%*s"+chufa_msg+"%*s") )
			{
				me->set_temp("xyzx_sys_chufa", chufa_cmds);
				break;
			}
		}
	}

	return;
	// --------------------------------------------------------------------
}

void write_prompt()
{
	if ( sizeof(msg_buffer) )
	{
		receive(BOLD +"[����ʱ�ݴ�ѶϢ]\n" + NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
	write(NOR"��"NOR);
}


void receive_snoop(string msg)
{
	receive("%" + msg);
}
