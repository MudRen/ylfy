//zhanqi.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能对自己使用。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if ( me->query_skill("shushan-force",1) < 100)
		return notify_fail("你的蜀山心法还不够娴熟。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");
	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision( HIM "$N微一凝神，运起蜀山心法，一股天罡战气从丹天直冲天顶。\n" NOR, me);

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
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 600);
	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/damage", - amount);
		me->add_temp("apply/dodge", - amount);
		me->add_temp("apply/strength", -amount);
		me->add_temp("apply/intelligence", -amount);
		me->add_temp("apply/constitution", -amount);
		me->add_temp("apply/dexerity", -amount);
		me->delete_temp("powerup");
		tell_object(me, HIM"你的天罡战气循环一周天完毕，将内力收回丹田。\n"NOR);
	}
}
