// suodi.c 飞天御剑流.抄刃止刃

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("飞天御剑流.抄刃止刃只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 60)
		return notify_fail("你的杀意心法火候不够。\n");
    if ( me->query_skill_mapped("blade") != "huoxinliu-jianfa")
		return notify_fail("你必须激发［活心流剑法］才能使用「抄刃止刃」！\n");
	if((int)me->query_skill("huoxinliu-jianfa",1) < 120)
		return notify_fail("你的神谷活心流的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("blade") < 30)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");
	if( userp(me) && !me->query("feitian/chaodao"))
		return notify_fail("你只听说过,但不会用「抄刃止刃」！\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("你的内力不够。\n");

	msg = HIW "$N双手交叉,以手背抵挡$n的武器,使出了这至高防御止刃术。\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += HIW " 结果$p被$P一把架住动弹不得！\n" NOR;
		if (!target->is_busy())
		{
			target->start_busy( (int)me->query_skill("huoxinliu-jianfa",1) / 60 + 2 );
		}
	}
	else
	{
		msg += HIC"可是$p看破了$P的企图，收回了手中的武器。\n"NOR NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	me->add("neili", - 60);
	if(!target->is_fighting(me)) target->fight_ob(me);
	if( me->query("xyzx_sys/level") > (int)target->query("xyzx_sys/level")/3 )
	{
		attack_time = (int)me->query_skill("huoxinliu-jianfa", 1) / 70;
		msg = HIC "$N双手交叉,以手背抵挡武器,使出了高防御止刃术。\n";
		target->start_busy(1);
		message_vision(msg, me, target);
		if ( attack_time < 1 ) attack_time = 1;
		if ( attack_time > 50 ) attack_time = 50;
		    me->add_temp("lianzhao", attack_time);
		for(i = 0; i < attack_time; i++)
		{
			msg = HIM "$N以刀柄刺对手怀内,使出了至高攻击抄刃术！\n" NOR;
			COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		}
	}
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(3);
	return 1;
}

