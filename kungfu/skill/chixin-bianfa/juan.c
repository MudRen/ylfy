// juan.c 风卷残云
#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("juan") )
		return notify_fail("你已经在使用风卷残云了。\n");
	skill = me->query_skill("chixin-bianfa",1);

	if( !(me->is_fighting() ))
		return notify_fail("风卷残云只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("shen") < 0)
		return notify_fail("你的侠义正气太低了，无法集中心志！\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有兵刃，你不用担心。\n");

	if( skill < 50)
		return notify_fail("你的痴心鞭法等级不够, 不能使用风卷残云！\n");
	if ((int)me->query_skill("wangran-xinfa", 1) < 50)
		return notify_fail("你的本门心法火候不够，无法使用。\n");
	if ((int)me->query_skill("shuiyue", 1) < 50)
		return notify_fail("你的本门轻功火候不够，无法使用。\n");
	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法使用风卷残云！\n");

	msg = HIW "$N默念口诀，打算施展风卷残云绝技. \n"NOR;
	message_vision(msg, me);
	if (me->query("family/family_name") == "痴心妄想门")
	{
		(dp = target->query_skill("parry") / 3);
	}
	else
	{
		(dp = target->query_skill("parry") / 3 * 2);
	}
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp || random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = WHT"$N挥舞手中"+ NOR+weapon->name()+ WHT"卷向$n, $n"WHT"顿时觉得眼前一花，手腕一麻，" NOR+ weapon2->name() +WHT"脱手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		me->start_busy(1+random(1));
	}
	else
	{
		msg = RED"可是$n"RED"的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(1+random(2));
	}
	message_vision(msg, me, target);

	return 1;
}
