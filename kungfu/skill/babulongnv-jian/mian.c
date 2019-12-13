// mian.c 八部龙女剑。绵绵剑气

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「绵绵剑气 」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	if( (int)me->query_skill("babulongnv-jian", 1) < 100 )
		return notify_fail("你的八部龙女剑法不够娴熟，不会使用「绵绵剑气 」。\n");
	i = me->query_skill("babulongnv-jian",1);
	msg = HIM "$N剑光斗长，射出无数如丝一般的剑气，绵绵不决的向$n缠绕过去。\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/5 || random(me->query("sword")) > target->query("dodge")/3 )
	{
		msg += HIC " 结果$p被$P射出的丝般剑气包裹在其中，动弹不得。\n" NOR;
		
		if(i > 20)i = 20;

		target->start_busy(i);
		target->apply_condition("no_perform", i);
		me->add("neili", -200);
	}
	else
	{
		msg += "可是$p看破了$P的企图，向后急跃，脱身出去。\n" NOR;
		me->start_busy(2);
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

