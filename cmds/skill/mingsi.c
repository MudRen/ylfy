// respirate.c

#include <skill.h>
// inherit F_CLEAN_UP;
private int mingsi_cost;
int mingsing(object me);
int halt_mingsi(object me);
int main(object me, string arg)
{
	object where = environment(me);
	seteuid(getuid());
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if( me->is_fighting() )
		return notify_fail("战斗也是一种修行，但不能和法力的修行同时进行。\n");
	if (me->query_skill("spells")<15)
		return notify_fail("你必须先学些基本法术。\n");
	if( !arg || !sscanf(arg, "%d", mingsi_cost))
		return notify_fail("你要花多少精力修行？\n");
	if (mingsi_cost < 10)
		return notify_fail("你最少要花 10 点精力才能进行修行。\n");
	if( (int)me->query("jingli") < mingsi_cost )
		return notify_fail("你现在精力不足，无法修行法力！\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");
        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");
	write("你闭上眼睛开始冥思。\n");
	me->set_temp("pending/mingsi", 1);
	me->set_temp("mingsi_cost", mingsi_cost);
	message("vision",me->name()+"盘膝坐下，开始冥思悟道。\n", environment(me),({me}));
	me->start_busy((: mingsing :), (: halt_mingsi :));
	return 1;
}
int mingsing(object me)
{
	int mingsi_cost = (int)me->query_temp("mingsi_cost");
	int fashufali_gain =2*(int)me->query_skill("spells",1);
	if (mingsi_cost < 1)
		return 0;
        if (mingsi_cost < fashufali_gain) fashufali_gain = mingsi_cost;
	if (mingsi_cost>2*fashufali_gain) fashufali_gain = mingsi_cost/2;
	
	me->add("fashufali", fashufali_gain);
	me->set_temp("mingsi_cost", mingsi_cost -= fashufali_gain);
	me->add("jingli", -fashufali_gain);
	if (mingsi_cost > 0)
		return 1;
	me->set_temp("pending/mingsi", 0);
	mingsi_cost = 0;
	message_vision("$N冥思完毕，睁开双眼，站了起来。\n", me);
	if((int)me->query("fashufali") < (int)me->query("max_fashufali") * 2)
		return 0;
	else {
		if ((int)me->query("max_fashufali") > (int)me->query_skill("spells") * 5 +15)
		{
			write("你的法力修为似乎已经达到了瓶颈。\n");
me->set("fashufali", (int)me->query("max_fashufali")*2);	
			return 0;
		}
		else
		{
			me->add("max_fashufali", 1);
			me->set("fashufali", (int)me->query("max_fashufali"));
			write("你的法力增加了！！\n");
			return 0;
		}
	}
}
int halt_mingsi(object me)
{
//	mingsi_cost = 0;
	if ((int)me->query("fashufali") > (int)me->query("max_fashufali") * 2)
		me->set("fashufali", (int)me->query("max_fashufali") * 2);
	me->set_temp("pending/mingsi", 0);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : mingsi [<耗费「精力」的量>]
 
冥思修行，利用「炼精化神，炼神修法，炼法悟道」的方法将你的精力
转变成法力。
HELP
        );
        return 1;
}
