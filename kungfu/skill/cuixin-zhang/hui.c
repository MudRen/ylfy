// po.c 「催心掌」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	int skill, jing_cost;
//    mapping my_fam  = me->query("family");
	skill = me->query_skill("cuixin-zhang",1);
	if (me->query_int()<50)
		jing_cost = (int)me->query_int() - 50;
	else    jing_cost=1;
	if( me->is_fighting() )
		return notify_fail("「催心掌」不能在战斗中演练。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你不能拿兵器。\n");
	if( !skill || (skill < 60))
		return notify_fail("你的催心掌等级不够, 不能演练「催心掌」！\n");
	if ( (string)me->query("family/family_name") != "玄天派")
		return notify_fail("「回折式」只有玄天派传人才能使用。\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，没有力气演练「催心掌」！\n");
	if (me->query_skill("unarmed",1)<= skill)
		return notify_fail("你的基本拳脚不够，无法通过演练「催心掌」提高催心掌的技巧！\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「催心掌」！\n");
	msg = HIC "$N盘膝而坐，吐气开声，一式「回折拍」幻出满天掌影。\n" + NOR;
	message_vision(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60)
		me->improve_skill("cuixin-zhang", 10);
	else if (skill < 90)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() - 9));
	else if (skill < 140)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 2 - 9));
	else if (skill < 200)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 4 - 9));
	else
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 8 - 9));
	msg = MAG"$N的摧心掌力加强了。\n"NOR;
	if (random(10)>8)    me->start_busy(1);
	message_vision(msg, me);
	return 1;
}
