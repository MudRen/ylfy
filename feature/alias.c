// alias.c
//为了安全起见增加了部分系统检查(心跳、恶意代码、闭关)

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
		tell_object(me, HIR"\n\n侮天鬼王突然在一阵烟雾中出现。\n\n侮天鬼王喝道：你老在吵我睡觉，你去死吧!!!\n\n"NOR);
		if ( me->is_ghost() )
		{
		    if ( me->query_condition("killer") )
		    {
			tell_object(me, HIW"你刷屏过快，接下来一分钟内系统不再接受你的指令！\n"NOR);
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
			tell_object(me, HIW"你刷屏过快，接下来一分钟内系统不再接受你的指令！\n"NOR);
			me->set("neili", 0);
			me->set("jingli", 0);
			block_cmds_do = 30;
		    }
		}
	    }		
	    if ( cmd_time > MAX_PLAYER_CMD )
	    {
		tell_object(me, HIR"\n\n侮天鬼王突然在一阵烟雾中出现。\n\n侮天鬼王喝道：你再这样吵我睡觉，我就不客气鸟!!!\n\n"NOR);
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
	    no_cmds += "、" + cmds_go[i];
    }
    no_cmds += NOR")";
    if ( member_array(verb, cmds_go) != -1 )
    {
	tell_object(this_object(), "您不能把保留字串"+no_cmds+"当作简化指令。\n");
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
	    tell_object(this_object(), "您设定的 alias 太多了，请先删掉一些不常用的。\n");
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
	    write(HIW"倒数第 "HIY+chinese_number(cmd_sign)+HIW" 条历史指令："NOR+history[cmd_now]+"\n");
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
