// say.c by macrohard 2000

#include <ansi.h>

inherit F_CLEAN_UP;
void delete_busy();
int main(object me, string arg)
{
	if (!arg)
	{
		if(me->is_busy() && me->query_temp("say_busy"))
		{
			if(!me->is_ghost() && userp(me))
				me->add("jing",-5);

			write("你自言自语太快， 一不小心咬到了舌头!\n");
			return 1;
		}
		
		if( time()-me->query_temp("say1")<1 && !wizardp(me) )
		{
			me->start_busy(4);
			me->set_temp("say_busy",1);
			remove_call_out("delete_busy");
			call_out("delete_busy",4);
			
			if(!me->is_ghost() && userp(me))
				me->add("jing",-5);
			
			write("别急，慢慢说!\n");
			return 1;
		}
		
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",environment(me), me);
		me->set_temp("say1",time());
		return 1;
	}
	
	if(me->is_busy() && me->query_temp("say_busy"))
	{
		if(!me->is_ghost() && userp(me))
			me->add("jing",-5);
		
		write("你说话太快，一不小心咬到了舌头!\n");
		return 1;
	}
	
	if( time()-me->query_temp("say1")<1 && !wizardp(me) )
	{
		me->start_busy(4);
		me->set_temp("say_busy",1);
		remove_call_out("delete_busy");
		call_out("delete_busy",4);
		
		if(!me->is_ghost() && userp(me))
			me->add("jing",-5);
		
		write("别急，有话好好讲！\n");
		return 1;
	}
	
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 )
	{
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
	
	write( CYN "你说道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "说道：" +  arg + "\n" NOR,environment(me), me);
	if ( playerp(me)) me->set_temp("say1",time());
        
	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

void delete_busy()
{
	object ob;

	if(!ob)
		return 0;

	if(ob->query_temp("say_busy"))
		ob->delete_temp("say_busy");
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
