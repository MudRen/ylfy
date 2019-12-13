// reserve.c 蛤蟆功经脉倒转

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	object weapon;
	int skill;

    if( target != me )
		return notify_fail("你只能用蛤蟆功来提升自己的战斗力。\n");
	
	if( (int)me->query_skill("hamagong", 1) < 40 )
		return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("hmg_dzjm") || me->query_temp("powerup") )
		return notify_fail("你已经倒转经脉提升战斗力了。\n");

	skill = me->query_skill("hamagong",1);
	message_vision( HIR "$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，防御力大增。\n" NOR, me);

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

	me->set_temp("hmg_dzjm", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), 600);
	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);
	return 1;
}

void remove_effect(object me, int amount)
{
		if (!me) return;
	if ( (int)me->query_temp("hmg_dzjm") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/damage", - amount);
		me->add_temp("apply/dodge", - amount);
		me->add_temp("apply/strength", -amount);
		me->add_temp("apply/intelligence", -amount);
		me->add_temp("apply/constitution", -amount);
		me->add_temp("apply/dexerity", -amount);
	    me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "你双手一撑，一跃而起，将内力收回丹田。\n");
}
}