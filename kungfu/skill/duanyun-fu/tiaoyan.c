// tiaoyan.c 夺命三斧之「挑眼式」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	damage = (int)me->query_skill("duanyun-fu",1);
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「挑眼式」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "正象只无头苍蝇，快放胆攻击吧。\n");
	msg = HIG "$N使出夺命三斧之「挑眼式」，斧尖疾挑$n双眼。\n";

	me->start_busy(random(3));
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += "结果$p只觉得眼前一黑，双眼一阵剧痛，接着什么也看不见了。\n" NOR;
		target->start_busy( (int)me->query_skill("duanyun-fu") / 50 + 2);
		target->receive_damage("qi",damage,me);
	}
	else
	{
		msg += "可是$p看破了$P的企图，并急忙躲开了。\n" NOR;
		me->start_busy(random(2));
	}
	message_vision(msg,me,target );

	return 1;
}

