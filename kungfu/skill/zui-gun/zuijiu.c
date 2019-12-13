// zuijiu.c 八仙醉打

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i, attack_time;
	string msg;
	int extra;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) || !living(target))
		return notify_fail("「八仙醉打」只能在战斗中对对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club" || me->query_skill_mapped("club") != "zui-gun")
		return notify_fail("你现在无法使用「八仙醉打」。\n");

	if( (int)me->query_skill("zui-gun",1) < 500 )
		return notify_fail("你的醉棍不够娴熟，不会使用「八仙醉打」！\n");

	if( (int)me->query("str") < 30 )
		return notify_fail("你的臂力不够强，不能使用「八仙醉打」！\n");

	if( (int)me->query("max_neili") < 200000 )
		return notify_fail("你的内力太弱，不能使用「八仙醉打」！\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力太少了，无法使用出「八仙醉打」！\n");
	
	extra = (int)me->query_condition("drunk");
	attack_time = (int)me->query_skill("zui-gun", 1) /100;

	message_vision(HIY"\n$N突然一个醉嗝，顿时借着酒劲猛打，醉棍威力大增！\n"NOR,me);
	if (random(2)==0) target->apply_condition("no_perform", 3);
	if (attack_time > 50) attack_time = 50;
	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
    me->add_temp("lianzhao",attack_time);
	for(i=0; i < attack_time; i++)
	{
		if(!me->is_killing(target) && !target->is_killing(me) && !target->is_fighting(me))
			break;
		//msg = HIR  "$N突然一个醉嗝，不知从何处打出第"+(i+1)+"棍！\n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->add("jing", 20);
	me->start_busy(3);
	return 1;
}
