// feitian.c 「总诀式」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;

	skill = me->query_skill("babulongnv-jian",1);
	jing_cost = (int)me->query("int") - 45;

	if( me->is_fighting() )
		return notify_fail("「八部飞天」不能在战斗中演练。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，没有力气演练「八部飞天」！\n");

	if( me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「八部飞天」！\n");

	msg = HIC "$N使出八部龙女剑之「八部飞天」，手中" + weapon->name() + ""HIC"围着自己不停绕动。\n";
	message_vision(msg, me);

	me->add("neili", -50);
	me->add("jing", jing_cost);

	if ( skill < 60)
		me->improve_skill("babulongnv-jian", 10);
	else if (skill < 90)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") - 8));
	else if (skill < 140)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 2 - 8));
	else if (skill < 200)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 4 - 8));
	else
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

	msg = MAG"$P的「八部龙女剑法」进步了！\n"NOR;
	me->start_busy(random(3));

	message_vision(msg, me);

	return 1;
}

