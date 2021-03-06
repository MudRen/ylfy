// guard.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
"north":        "北",
"south":        "南",
"east":	        "东",
"west":	        "西",
"northup":      "北上",
"southup":      "南上",
"eastup":       "东上",
"westup":       "西上",
"northdown":    "北下",
"southdown":    "南下",
"eastdown":	    "东下",
"westdown":	    "西下",
"northeast":    "东北",
"northwest":    "西北",
"southeast":    "东南",
"southwest":    "西南",
"up":           "上",
"down":	        "下",
"out":	        "外面",
"in" :          "里",
"enter" :       "里面",
]);

int main(object me, string arg)
{
	object ob,obj,*enemy;
	int i;
	
	if( me->is_busy() )
		return notify_fail("你现在没有办法分心去做这类事！\n");
	
	if( !arg || arg=="" )
		return notify_fail("指令格式：guard <生物> | <物品> | <方向>\n");

	if( arg == "None" && me->query_temp("guard_ob"))
	{
		me->delete_temp("guard_ob");
		write("什么也不用守了，真是好轻松。\n");
		return 1;
	}

	if( arg )
	{
		if( environment(me)->query("exits/" + arg) )
			ob = environment(me);
		else
			ob = present(arg,environment(me));
	}

	if( !ob )
		return notify_fail("你要守卫谁，什麽，或是哪个方向？\n");
	
	if( arg == me->query_temp("guard_ob") )
	{
		if( ob->query("exits/" + arg) )
		{
			write("你正守住往 " + default_dirs[arg] + " 的方向,不准任何人离开.\n");
			return 1;
		}
		
		if( living(ob) )
		{
			write("你正在守护著 " + ob->query("name") + " 。\n");
			return 1;
		}
		else
		{
			write("你正守在 " + ob->query("name") + " 一旁，防止别人拿走。\n");
			return 1;
		}
	}
	
	if( ob==me )
		return notify_fail("守卫自己？不用说你也会做，对吧。\n");

	if(ob->query_temp("guard_for"))
		obj = find_living(ob->query_temp("guard_for"));

	if( objectp(obj) )
	{
		if( environment(me) == environment(obj) && ob->query_temp("guard_for") != me->query("id") )
			return notify_fail(ob->query("name") +" 已经有人守护着了。\n");
	}

	if( ob->query("exits/" + arg) )
	{
		if( ob->query("no_fight") )
			return notify_fail("这里不准战斗,也不准堵住别人去路！\n");

		message_vision("$N开始守住往 " + default_dirs[arg] + " 的方向不让任何人通行。\n", me);
	}
	else
	{
		if( living(ob) )
		{
			if( !userp(ob) )
				ob->set_temp("guard_for",me->query("id"));
			message_vision("$N开始保护$n。\n", me, ob);
		}
		else
			message_vision("$N站到地上的$n一旁守著，以免别人取走。\n", me, ob);
	}

	if(me->query_temp("guard_ob"))
		obj = find_living(me->query_temp("guard_ob"));

	if( objectp(obj) && environment(obj) )
	{
		obj->delete("guard_for");
		if(obj != me)
		{
			tell_object(obj, me->query("name") + " 不再保护你了。\n");
			tell_object(me, "你停止了对 " + obj->query("name") +" 的保护。\n");
		}
	}

	me->set_temp("guard_ob", arg);
	
	if( !userp(ob) && ob->query("combat_exp") > me->query("combat_exp") )
	{
		enemy = ob->query_enemy();
		i = sizeof(enemy);
		while(i--)
		{
			if( enemy[i] && living(enemy[i]) )
			{
				if( userp(enemy[i]) )
				{
					enemy[i]->start_busy(5);
					enemy[i]->fight_ob(me);
				}
				else
					enemy[i]->kill_ob(me);
				
				me->kill_ob(enemy[i]);
				ob->remove_all_killer();
			}
		}
	}
	
	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某个出口>|None]

这个指令有三种作用方式，分别如後：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由於只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙著其他事，别人就无法拿走这件东西。若你离开后再回
                  来，只要东西还在，那仍将在你守护之下。

guard <某个出口>  守住某个出口防止所有人从这个出口离开，可以用来阻拦善於逃跑
                  的敌人或拦路打劫做坏事。
                  目前暂不开放守出口这个功能。

guard None      取消先前的 guard 对象。

注意，通常除了 guard <某人> 的情形以外，只要你一移动，guard 的状态就会解除。
TEXT
	);
	return 1;
}
