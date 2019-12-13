// alias.c
//Ϊ�˰�ȫ��������˲���ϵͳ���(������������롢�չ�)

#include <command.h>

#define MAX_REPEAT 40
#define MAX_ALIASES 40
#define MAX_PLAYER_CMD 10
#define MAX_KILL_TIMES 5
#define HISTORY_BUFFER_SIZE 10

mapping alias;
nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_cmd_time, cmd_time=0, kill_time=0;
nosave int block_cmds_do = 0;
nosave string *cmds_go = ({"\"", "\"", "$"});

string process_input(string str)
{
    string *args, command, argstr, cmd, time;
    int i, j;
    object env;
    object me = this_object();

    time = sprintf("%d", time());

    if ( !objectp(me) || !stringp(str) || str=="" || !(env=environment(me))) return "";
    if ( interactive(me) )
    {
	if ( !query_heart_beat(me) )
	{
	    "/cmds/usr/quitfyup"->main(me);
	    return "";
	}
	if ( me->query("lixian/biguan") )
	{
	    me->delete("lixian/biguan");
	    "/cmds/usr/quit"->main(me);
	    return "";
	}
	if ( !wizardp(me) && me->query("block") 
		&& base_name(env) != "/clone/misc/block" )
	{
	    me->move("/clone/misc/block");
	    return "";
	}
    }
    if ( me->query_temp("disable_inputs") ) return "";
    if ( me->query_temp("block_msg/all") ) return "";
    if ( !living(me) ) return "";

    /*
       if ( kill_time > 0 ) cmd_time += kill_time;
       else cmd_time++;
       */
    cmd_time++;

    if ( playerp(me) )
    {
	if ( time()-last_cmd_time < 1 )
	{
	    if ( kill_time > MAX_KILL_TIMES )
	    {
		tell_object(me, HIR"\n\n�������ͻȻ��һ�������г��֡�\n\n��������ȵ��������ڳ���˯������ȥ����!!!\n\n"NOR);
		if ( me->is_ghost() )
		{
		    if ( me->query_condition("killer") )
		    {
			tell_object(me, HIW"��ˢ�����죬������һ������ϵͳ���ٽ������ָ�\n"NOR);
			block_cmds_do = 30;
		    }
		    else
		    {
			me->set("kickout_time", time());
			me->kick();
		    }
		}
		else
		{
		    cmd_time=0;
		    kill_time=0;
		    if ( !me->query("xyhy_type") )
			me->unconcious();
		    else
		    {
			tell_object(me, HIW"��ˢ�����죬������һ������ϵͳ���ٽ������ָ�\n"NOR);
			me->set("neili", 0);
			me->set("jingli", 0);
			block_cmds_do = 30;
		    }
		}
	    }		
	    if ( cmd_time > MAX_PLAYER_CMD )
	    {
		tell_object(me, HIR"\n\n�������ͻȻ��һ�������г��֡�\n\n��������ȵ���������������˯�����ҾͲ�������!!!\n\n"NOR);
		cmd_time=0;
		kill_time++;
	    }
	}
	else   
	{
	    cmd_time=0;
	    if ( time()-last_cmd_time == 1 ) 
		kill_time>0?kill_time--:kill_time=0;
	    else 
		kill_time=0;
	}

	last_cmd_time=time();

	if ( str == last_input )
	{
	    repeat_cnt++;
	}
	else 
	{
	    repeat_cnt = 0;
	    last_input = str;
	}
    }

    if( str[0]=='!' ) 
    {
	if( pointerp(history) && sizeof(history) ) 
	{
	    if( sscanf(str, "!%d", i) )
		str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
	    else
		str = history[last_cmd];
	}
	else
	    return "";
    } 
    else 
    {
	if( !pointerp(history) ) 
	    history = allocate(HISTORY_BUFFER_SIZE);

	last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;

	history[last_cmd] = str;
    }

    if( mapp(alias) ) 
    {
	if( !undefinedp(alias[str]) )
	    return replace_string( alias[str], "$*", "" );

	if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) 
	{
	    if ( sscanf(alias[cmd], "%*s$%*s") )
	    {
		cmd = replace_string( alias[cmd], "$*", argstr );
		if ( sscanf(argstr, "%*s %*s") )
		{
		    args = explode(argstr, " ");
		    if( (j = sizeof(args)) )
		    {
			for(i=0; i<j; i++)
			{
			    cmd = replace_string( cmd, "$" + (i+1), args[i] );
			}
		    }
		}
	    }
	    else
		cmd = alias[cmd] + " " + argstr;
	    return cmd;
	}
    }

    command=(string)ALIAS_D->process_global_alias(str);

    if(playerp(me))
	if (me->query_temp("big5") ) command=LANGUAGE_D->Big52GB(command);

    return command;
}

int set_alias(string verb, string replace)
{
    string no_cmds;
    int i;

    no_cmds = "("HIY;
    for ( i = 0; i < sizeof(cmds_go); i++)
    {
	if ( i == 0 )
	    no_cmds += cmds_go[i];
	else
	    no_cmds += "��" + cmds_go[i];
    }
    no_cmds += NOR")";
    if ( member_array(verb, cmds_go) != -1 )
    {
	tell_object(this_object(), "�����ܰѱ����ִ�"+no_cmds+"������ָ�\n");
	return 0;
    }

    if( !replace )
    {
	if( mapp(alias) ) map_delete(alias, verb);
	return 1;
    }
    else
    {
	if( !mapp(alias) )
	    alias = ([ verb:replace ]);
	else if( sizeof(alias) > MAX_ALIASES )
	{
	    tell_object(this_object(), "���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
	    return 0;
	}
	else
	    alias[verb] = replace;

	return 1;
    }
}

mapping query_all_alias()
{
    return alias;
}

void query_all_history()
{
    int cmd_now, cmd_sign;

    cmd_now=last_cmd;
    cmd_sign=1;
    do
    {
	if ( history[cmd_now] )
	    write(HIW"������ "HIY+chinese_number(cmd_sign)+HIW" ����ʷָ�"NOR+history[cmd_now]+"\n");
	cmd_now--;
	cmd_sign++;
	if ( cmd_now < 0 )
	    cmd_now=HISTORY_BUFFER_SIZE+cmd_now;
	if ( cmd_now > HISTORY_BUFFER_SIZE-1 )
	    cmd_now=cmd_now%(HISTORY_BUFFER_SIZE-1);
    }
    while ( cmd_now != last_cmd );
}

void degression_cmds_block()
{
    if ( !block_cmds_do ) return;
    block_cmds_do--;
}
