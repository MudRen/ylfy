#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「"+HIC"爱爱"NOR+"」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("adai-quanfa", 1) < 500 )
		return notify_fail("你的啊呆拳法不够熟练，不会使用「"+HIC"爱爱"NOR+"」。\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("你的内力修为还不够高。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够了。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你先放下手中的武器再说吧？！\n");

	msg = HIC"$N大叫一声，使出啊呆拳法的最后一招「亲爱的，我爱死你了」，双手温柔的像$n脸上摸去。。。 \n"NOR;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/3)
	{
		me->start_busy(1);
		target->start_busy(20);

		damage = me->query_skill("unarmed") + me->query_skill("force");
		damage = damage + random(damage)*2;

		target->receive_damage("qi", damage*4);
		target->receive_wound("qi", damage*4);
		me->add("neili", -damage-500);
		msg += HIR "$n脸上一阵红晕，倒在$N的怀里，嘴里叫道：我要，我要啊！\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		return 1;

	}
	else
	{
		me->start_busy(5);
		me->add("neili",-100);
		msg += HIG"$n说道:这种淫荡的武功怎么可能伤的了我,我可是淫王之王啊,头一歪,流了一地的口水,逃出了$N这一招。\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}


