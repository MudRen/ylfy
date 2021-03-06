// 「玄幻一斩」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage, damage2;
	string msg;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("开什么玩笑，没刀子也想使用「玄幻一斩」？\n"NOR);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「玄幻一斩」只能对战斗中的对手使用。\n");
	if ( (string)me->query("family/family_name") != "玄天派")
		return notify_fail("「玄幻一斩」只有玄天派传人才能使用。\n");

	if ((int)me->query_skill("tianxin-blade", 1) < 1000 )
		return notify_fail("你的天行刀法不够娴熟，还使不出「玄幻一斩」。\n"NOR);
	if ((int)me->query_skill("cuixin-zhang", 1) < 1000 )
		return notify_fail("你没能领悟催心掌的阴柔内劲，还使不出「玄幻一斩」。\n"NOR);
	if ((int)me->query_skill("lingyunbu", 1) < 1200 )
		return notify_fail("你的凌云步法没学到家，不够身法配合「玄幻一斩」。\n"NOR);
	if ((int)me->query_skill("yijing-force", 1) < 1000 )
		return notify_fail("你的易经神功火候不够，「玄幻一斩」不成招式。\n"NOR);
	if ((int)me->query("max_neili")<50000)
		return notify_fail("你的内力修为不足，无法运足「玄幻一斩」的内力。\n"NOR);
	if ((int)me->query("neili")<200)
	{
		return notify_fail("你现在内力不够，没能将「玄幻一斩」完美使出！\n"NOR);
	}
	msg = HIC "      $N凝神聚元，集中全身力量在手中利器之上，\n"NOR;
	msg += HIC"      准备施展天行刀法究极绝技「玄幻一斩」！！\n"NOR;
	msg += HIC"      $n被$N的杀气震慑，竟然动弹不得！！\n"NOR;
	if (random(me->query_skill("blade"))>target->query_skill("force")/2)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill("tianxin-blade")*5+(int)me->query_skill("force")*2;
		damage = damage + random(damage);
		if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
		if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


		damage2 = (int)me->query_skill("tianxin-blade")*5+(int)me->query_skill("force")*2;
		damage2 = damage2 + random(damage2);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		if (damage>target->query("max_jing",1)/3) damage = random (target->query("max_jing",1)/4);

		target->receive_damage("jing", damage2);
		target->receive_wound("jing", damage2/2);
		msg += HIR"$n眼睁睁看着$N聚气成龙，充满杀意刀锋正缓缓的向自己斩下却一动也不能动！\n"NOR;
		msg += HIR"鲜血溅射而出，$n跟本没觉得疼痛，只知道冷冰冰的刀锋已经切入自己体内！！\n"NOR;
		me->add("neili", -4000);
	}
	else
	{
		me->start_busy(random(3));
		msg += HIY"$p定力非常，终于在$P的刀锋斩在自己身上的时候恢复了\n"NOR;
		msg += HIY"心神，连忙向后退去，躲开了这致命一击！！\n"NOR;
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	me->fight_ob(target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

