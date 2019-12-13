// surrender.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	
	if( !me->is_fighting() )
		return notify_fail("投降？现在没有人在打你啊....？\n");
	ob = me->query_temp("last_opponent");
	if (!ob)
		return notify_fail("投降？现在没有人在打你啊....？\n");
	if(living(ob))
	if ( ob->is_killing()) {
		message_vision(RED "$N向$n求饶，但是$n大声说道："
			+ RANK_D->query_rude(me) + "废话少说，纳命来！\n " NOR, me,ob);
		return notify_fail("看来敌人不想放过你啊....\n");
	}
        me->remove_enemy(ob);
        ob->remove_enemy(me);
        ob->remove_killer(me);
        me->remove_killer(ob);
	if (ob->query_leader()==me)
		ob->set_leader(0);
if( (int)me->query("weiwang") >= 100 )	
		me->add("weiwang", -10 );
	message_vision( HIW "\n$N说道：「不打了，不打了，我投降....。」\n\n" NOR, me);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : surrender
 
这个指令可以让你向敌人投降而终止战斗。但是，这样会降低你的江湖威望。
 
HELP
    );
    return 1;
}
 
