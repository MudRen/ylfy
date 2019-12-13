// sanjue 九阴三绝爪

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int str, dex, skill, i, damage;
	string msg;
	str = (int)me->query("str");
	dex = (int)me->query("dex");
	skill = (int)me->query_skill("jiuyin-baiguzhao", 1);
	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) )
		return notify_fail("「九阴三绝爪」只能在战斗中使用。\n");
	if( me->query_temp("weapon"))
		return notify_fail("你拿着武器怎么能使用「九阴三绝爪」！\n");
	if(me->query_skill("jiuyin-zhenjing",1) < 1000 )
		return notify_fail("你的九阴真经还不够娴熟，使不出「九阴三绝爪」绝技。\n");
	if( skill < 3000 )
		return notify_fail("你的九阴白骨爪还不够娴熟，使不出「九阴三绝爪」绝技。\n");

	if ( me->query_skill_mapped("unarmed") != "jiuyin-baiguzhao" )
		return notify_fail("你现在无法使用「九阴三绝爪」！\n");
	if( (int)me->query("max_neili") < 80000 )
		return notify_fail("你现在内力太弱，使不出「九阴三绝爪」。\n");
	if( (int)me->query("neili") < 8000 )
		return notify_fail("你现在真气太弱，使不出「九阴三绝爪」。\n");

	me->start_perform(2, "九阴三绝爪");
	message_vision(HIR"\n$N手臂突然伸长，向$n抓去！\n"NOR,me,target);
	message_vision(RED"\n$N所使的似乎是江湖中驰名的阴毒功夫九阴白骨爪，但是招数光明正大，威力强极！\n"NOR,me,target);
	if (!target->is_busy()) target->start_busy(5);
	me->add("neili", -1000);
	me->add_temp("apply/strength",str/2);
	me->add_temp("apply/dexerity",dex/2);
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage", skill/2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/damage", -skill/2);
	me->add_temp("apply/attack", -skill/2);
	me->add_temp("apply/strength",-str/2);
	me->add_temp("apply/dexerity",-dex/2);

	msg = HIB "\n$N一声怪啸，绕着$n急转数圈，而后施展出「摧筋破骨」，双爪齐出，直插$n前胸。\n"NOR;
	if (userp(target))
	{
		if ( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/4 )
		{
			msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
			damage = skill * 50 + random(skill);
			target->add("jing",-damage);
			target->add("eff_jing",-damage/2);
			msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
			me->add("neili", - 600);
		}
		else
		{
			msg += HIY"$N只觉$n内力浑厚，双爪竟不能惯胸而入。\n" NOR;
		}
		message_vision(msg, me, target );
		me->start_busy(2 + random(i));
		if (!target->is_busy()) me->start_busy(5);
	}
	else
	{
		if (random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
		{
			msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
			damage = skill * 50 + random(skill);
			target->add("jing",-damage);
			target->add("eff_jing",-damage/2);
			msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
			me->add("neili", - 600);
		}
		else
		{
			msg += HIY"$N只觉$n内力浑厚，双爪竟不能惯胸而入。\n" NOR;
		}
		message_vision(msg, me, target );
		me->start_busy(2 + random(i));
		if (!target->query_condition("no_perform") )
		{
			target->apply_condition("no_perform", 10);
			message_vision( HIC"\n$n被$N刺中穴道，手腕酥麻无力，运转失灵，难以施展外功。\n" NOR, me, target);
		}
		if (!target->is_busy()) me->start_busy(4);
	}
	return 1;
}
