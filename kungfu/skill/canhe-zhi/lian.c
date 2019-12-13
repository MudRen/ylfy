// lian.c 莲花指

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int skill,level;


	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「莲花指」只能对战斗中的对手使用。\n");

	if( me->query_skill("canhe-zhi",1) < 200 )
		return notify_fail("你的参合指火候不到，无法施展慕容家传绝学！\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 180)
		return notify_fail("你的神元功火候太浅。\n");

	if ((int)me->query_skill("canhe-zhi", 1) < 180)
		return notify_fail("你的参合指火候太浅。\n");
	if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
		return notify_fail("你的斗转星移火候太浅。\n");

	skill = me->query_skill("canhe-zhi", 1);

	if (me->query("neili") < 700)
		return notify_fail("你的真气不够，无法运用「莲花指」！\n");

	if (me->query_skill_mapped("unarmed") != "canhe-zhi")
		return notify_fail("你没有激发参合指, 不能使用「莲花指」！\n");

	msg = HIC "$N" HIC "五指伸出，宛若一朵盛开的莲花，轻飘飘的拂向$n" HIC "。\n" NOR;

	me->add("neili", -30);
	ap = me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
	dp = target->query_skill("dodge") + target->query_skill("parry") + me->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P逼得招架不迭，无暇旁顾。\n" NOR;
		target->start_busy(random(4) + 2);
	}
	else
	{
		msg += CYN "可是$p" CYN "看破了$P的企图，轻轻一跃，躲开了这一招。\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	msg = HIW "只见$N" HIW "身形一展，身法陡然变得诡异无比，聚力于指悄然点出，数股剑气直袭$n" HIW "要穴而去。\n" NOR;

	message_vision(msg, me, target);

	me->start_busy(3);
	me->add("neili", -300);
	level = me->query_skill("canhe-zhi", 1);
	me->add("apply/attack", level);
	msg = MAG "$N一指点向$n的幽门穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = YEL "$N二指点向$n的章门穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = WHT "$N三指点向$n的大横穴"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =RED "$N四指点向$n的紫宫穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIR "$N五指点向$n的冷渊穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIC "$N六指点向$n的天井穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIB "$N七指点向$n的极泉穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = GRN "$N八指点向$n的清灵穴" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("apply/attack", -level);

	return 1;
}

