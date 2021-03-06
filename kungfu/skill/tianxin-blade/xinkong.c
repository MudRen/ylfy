// po.c 「天马行空式」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;
//    mapping my_fam  = me->query("family");
	skill = me->query_skill("tianxin-blade",1);
	if (me->query_int()<50)
		jing_cost = (int)me->query_int() - 50;
	else    jing_cost=1;
	if( me->is_fighting() )
		return notify_fail("「天马行空式」不能在战斗中演练。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你必须先去找一把刀。\n");
	if( !skill || (skill < 60))
		return notify_fail("你的天行刀法等级不够, 不能演练「天马行空式」！\n");
	if ( (string)me->query("family/family_name") != "玄天派")
		return notify_fail("「天马行空式」只有玄天派传人才能使用。\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，没有力气演练「天马行空式」！\n");
	if (me->query_skill("blade",1)<= skill)
		return notify_fail("你的基本刀法不够，无法通过演练「天马行空式」提高天行刀法的技巧！\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「天马行空式」！\n");
	msg = HIC "$N将手中" + weapon->name() + HIC "一分，使出「天马行空式」凌空发出一十二刀。\n" + NOR;
	message_vision(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60)
		me->improve_skill("tianxin-blade", 10);
	else if (skill < 90)
		me->improve_skill("tianxin-blade", 10 + random((int)me->query_int() - 9));
	else if (skill < 140)
		me->improve_skill("tianxin-blade", 10 + random((int)me->query_int() * 2 - 9));
	else if (skill < 200)
		me->improve_skill("tianxin-blade", 10 + random((int)me->query_int() * 4 - 9));
	else
		me->improve_skill("tianxin-blade", 10 + random((int)me->query_int() * 8 - 9));
	msg = MAG"$P的「天行刀法」进步了！\n"NOR;
	if (random(10)>8)    me->start_busy(1);
	message_vision(msg, me);
	return 1;
}

