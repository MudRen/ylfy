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
		msg=msg[0..8000]+"\n\n£Æ£Æ£Æ\n";

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
	//  π”√BIG5µƒ
	//if ( query_ip_port(me) == BIG5_PORT )
	//	msg = efun::gbtobig5(msg);

	if ( prop == 1 )
	{
		// ‘∂≥Ãµ«¬Ω
		if ( msgclass == "telnet" )
		{
			receive(msg);
			return;
		}
		// Œ◊ ¶–≈œ¢
		if ( msgclass == "wiz" )
		{
			if ( !wizardp(me) ) return;
			if ( me->query("env/block_wiz_msg") ) return;
			receive(msg);
			return;
		}
		// ∞Ôª·–≈œ¢
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
		// ––◊ﬂ–≈œ¢
		if ( msgclass == "go" && me->query("env/block_go_msg") ) return;
		// ¡ƒÃÏ∆µµ¿
		if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 )
		{
			switch(subclass)
			{
				case "channel":
					if( !pointerp(ch = query("channels")) || member_array(msgclass, ch)==-1 )
					return;

					if ( !me->query("xieyi/zmud") )
					{
						if ( sscanf(msg,"%*s°æ√‘ŒÌ…≠¡÷°ø%*s") || sscanf(msg,"%*s°ææµª®ÀÆ‘¬°ø%*s")
							|| sscanf(msg,"%*s°º∂ƒ≥°œ˚œ¢°Ω%*s") || sscanf(msg,"%*s°æœµÕ≥æ´¡È°ø%*s")
							|| sscanf(msg,"%*s°æ[1;31mΩ≠∫˛◊∑…±¡Ó[1;34m°ø%*s") || sscanf(msg,"%*s°æ[1;33mΩ≠∫˛…‚√‚¡Ó[1;34m°ø%*s") )
						{
							if ( !sscanf(msg,"%*sptext%*s") )
								msg = PTEXT(msg);
						}
						//π˝¬Àæ…∞Ê±æTomudŒﬁ∑®Ω‚ ÕµƒANSI◊÷∑˚¥Æ
						if ( sscanf(msg,"%*sptext%*s") )
							msg = replace_string(msg,BLINK,"");
					}

					//‘ˆº”ªË√‘ªÚÀØ√ﬂ◊¥Ã¨ø…Ω” ’¡ƒÃÏ–≈œ¢
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
					//tell_object(me, HIY"\nƒ˙ ‰»ÎŒƒ◊÷∑¢¥Ùµƒ ±º‰≥¨π˝"HIC" ŒÂ "HIY"∑÷÷”¡À£¨ªπ «œ»œÎ∫√¡À‘ŸÀµ∞…°£\n"NOR);
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

	// ¥•∑¢
	// --------------------------------------------------------------------
	// ¥•∑¢ «πÿ±’µƒ
	if ( me->query("xyzx_chufa_stop") )
		return;

	// ”–Œ¥ÕÍ≥…µƒ¥•∑¢‘Ú‘›Õ£¥•∑¢µ»¥˝
	if ( me->query_temp("xyzx_sys_chufa") )
		return;

	// ≤ª «ª·‘±≤ªƒ‹ π”√¥•∑¢
	if ( !me->query("xy_huiyuan") )
		return;

	if ( !stringp(huiyuan = me->query("xy_huiyuan")) )
		return;

	if ( sscanf(huiyuan, "%dƒÍ%d‘¬%d»’", year, mon, day) != 3 )
		return;

	// ≤ª «ÕÊº“
	if ( !playerp(me) )
		return;

	// ºÏ≤È¥•∑¢µµ∞∏Œƒº˛
	if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) < 0 )
		return;

	file_str = read_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
	chufa_list = explode(file_str, "\n");
	v = sizeof(chufa_list);

	if ( v > CHUFA_CMD_SIZE )
		v = CHUFA_CMD_SIZE;

	// »•µÙ ANSI ◊÷∑˚¥Æ
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
		receive(BOLD +"[ ‰»Î ±‘›¥Ê—∂œ¢]\n" + NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
	write(NOR"°°"NOR);
}


void receive_snoop(string msg)
{
	receive("%" + msg);
}
