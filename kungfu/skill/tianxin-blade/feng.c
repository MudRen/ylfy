#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	me->clean_up_enemy();
	target = me->select_opponent();
	skill = me->query_skill("tianxin-blade",1);
	if( !(me->is_fighting() ))
		return notify_fail("「封」字决只能对战斗中的对手使用。\n");

	if ( (string)me->query("family/family_name") != "玄天派")
		return notify_fail("「封」字决只有通玄天传人才能使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有兵刃，你不用担心。\n");

	if( skill < 200)
		return notify_fail("你的天行刀法等级不够, 不能使用「封」字决！\n");
	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够，无法运用「封」字决！\n");
	if (me->query_temp("perform"))
		message_vision(HIC"$N气力一凝，施展开天行刀法「封」字刀决，手中刀刃随着对方兵器绞去。\n"NOR, me, target);

	damage = 10 * me->query_skill("blade");
	ap = skill+me->query_skill("blade",1);
	dp = target->query_skill("parry",1) + target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$n顿时觉得一股大力从$N刀上传来，一声轻呼，手腕一麻，手中";
		msg += weapon2->name();
		msg += "脱手而出！\n" NOR;
		target->receive_damage("qi", damage);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me))
			me->add("neili",-30);
		msg = "可是$n看破了$N的企图，立刻将手中" + weapon2->name() + "舞得风雨不透，使$N的「封」字决没有起到作用。\n"NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}


