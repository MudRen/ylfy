#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「"+HIG"摧心碎魂"NOR+"」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("cuixin-zhang", 1) < 500 )
		return notify_fail("你的摧心掌不够熟练，不会使用「"+HIG"摧心碎魂"NOR+"」。\n");

	if ( (string)me->query("family/family_name") != "玄天派")
		return notify_fail("「"+HIG"摧心碎魂"NOR+"」只有玄天派传人才能使用。\n");

	if( (int)me->query_skill("yijing-force", 1) < 500 )
		return notify_fail("你的易经神功不够熟练，不会使用「"+HIG"摧心碎魂"NOR+"」。\n");

	if( (int)me->query_skill("lingyunbu", 1) < 1000 )
		return notify_fail("你的凌云步法不够熟练，不能配合摧心掌使用「"+HIG"摧心碎魂"NOR+"」。\n");

	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("你的内力修为还不够高。\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("你的内力不够了。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你先放下手中的武器再说吧？！\n");

	msg = HIC "$N双手一分，施展出摧心掌之秘技"HIM+"「摧心碎魂」"+HIC"，向$n轻飘飘的拍出一掌！\n"NOR;

	if( random(me->query_skill("unarmed")) > target->query_skill("force")/5)
	{
		me->start_busy(1);
		target->start_busy(random(2));

		damage = me->query_skill("force") * me->query("con") + me->query_skill("unarmed")*2;

		damage = damage + random(damage);
		if (damage < target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2)
			damage = random (target->query("max_qi",1)/6);

		if (damage>target->query("max_qi",1)/3)
			damage = random (target->query("max_qi",1)/4);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -4000);
		msg += HIR"$n眼见这一掌柔弱无力，也不去理睬，当$N掌力击在身上只时才感到五内具焚！！\n"NOR;
		message_vision(msg, me, target );
		COMBAT_D->report_status(target);
		return 1;

	}
	else
	{
		me->start_busy(1);
		me->add("neili",-200);
		msg += HIY"$n眼镜一亮，看出这掌中蕴涵无穷力量，连忙后退躲开！\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

