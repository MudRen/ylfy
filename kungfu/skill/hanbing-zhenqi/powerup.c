// powerup.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能用寒冰真气提升自己的战斗力。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");
	if (me->query_skill("hanbing-zhenqi",1) < 100)
		return notify_fail("你的寒冰真气还不够娴熟。\n");
	
	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi",0);

	message_vision(HIB"$N微一凝神，全身一阵颤抖，默运寒冰真气。\n"NOR, me);
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
    me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),600);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
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
		tell_object(me, "你的寒冰真气运行完毕，将内力收回丹田。\n");
	}
}
