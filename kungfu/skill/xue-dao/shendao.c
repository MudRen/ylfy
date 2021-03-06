
// shendao.c  血刀「祭血神刀」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "blade")
		return notify_fail(RED"装备刀才能使用「祭血神刀」？\n"NOR);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「祭血神刀」只能对战斗中的对手使用。\n");
	if ((int)me->query_skill("xue-dao", 1) < 600 )
		return notify_fail(WHT"你血刀刀法不够娴熟，使不出「祭血神刀」。\n"NOR);
	if(!( me->query_temp("weapon")->id("xblade")))
		return notify_fail(WHT"你必须手持血刀，才能使出「祭血神刀」。\n"NOR);
	if ((int)me->query_skill("longxiang", 1) < 450 )
		return notify_fail(RED"你龙象般若功火候不够，使不出「祭血神刀」。\n"NOR);
	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
	if ((int)me->query("neili") < 600)
	{
		return notify_fail(HIC"你现在内力不够，没能将「祭血神刀」使完！\n"NOR);
	}
	msg = HIC "$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出，一片血光裹住刀影向$n当头劈落。\n\n"NOR;
	if ( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/5 )
	{
		damage = ((int)(me->query("shen")/-300))+(int)(me->query("shen")/-3000);
		if (damage < 0) damage = 30000;
		if (damage > 2000000) damage = 2000000;
		me->add("neili", -600);
		me->receive_wound("qi", me->query("qi")/10);
		me->start_busy(1);
		target->start_busy(random(3));
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		msg += HIR"\n$n疾忙侧身避让，但血刀疾闪，只觉眼前一阵血红，刀刃劈面而下，鲜血飞溅，惨声大嚎！\n"NOR;
	}
	else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20);
		msg += HIY"可是$n侧身避让，不荒不忙，躲过了$N的血刀。\n"NOR;
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
