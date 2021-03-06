// powerup.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用冷月神功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你的真气不够！");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	if ( me->query_skill("lengyue-shengong",1) < 100)
		return notify_fail("你的冷月神功还不够娴熟。\n");
	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(HIW "$N" HIW "全身关节“格啦格啦”一阵爆响，一股至阴的内劲从浑身经脉迸发出来。\n" NOR, me);

	me->add_temp("apply/attack", skill);
	tell_object(me,HIG"你的命中提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/damage", skill);
	tell_object(me,HIG"你的伤害提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dodge", skill);
	tell_object(me,HIG"你的闪避提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/strength",skill);
	tell_object(me,HIG"你的力量提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/dexerity",skill);
	tell_object(me,HIG"你的身法提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/constitution",skill);
	tell_object(me,HIG"你的根骨提高了"+chinese_number(skill)+"点!\n"NOR);
	me->add_temp("apply/intelligence",skill);
	tell_object(me,HIG"你的悟性提高了"+chinese_number(skill)+"点!\n"NOR);

	me->set_temp("powerup", 1);
    me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 600);
	if (me->is_fighting()) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/damage", - amount);
		me->add_temp("apply/dodge", - amount);
		me->add_temp("apply/strength", -amount);
		me->add_temp("apply/intelligence", -amount);
		me->add_temp("apply/constitution", -amount);
		me->add_temp("apply/dexerity", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的冷月神功运行完毕，将内力收回丹田。\n");
	}
}

