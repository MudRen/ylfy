// powerup.c 玉女心经加力

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if((string)me->query("family/family_name") != "古墓派" )
		return notify_fail("你又不是古墓弟子，怎么能用高深的玉女心经? \n");
	if( target != me )
		return notify_fail("你只能提升自己的战斗力。\n");
	if( (int)me->query("neili")<200)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");
	if( (int)me->query_skill("yunv-xinjing",1) < 100)
		return notify_fail("你的玉女心经还不够精熟。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision( HIC "$N脸色微微一沉，双掌向外一分，姿势曼妙，如一朵"HIW"白玉兰花"HIC"盛开在初冬的寒风中！\n" NOR, me);

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
		tell_object(me, "你的玉女心经运行完毕，将内力收回丹田。\n");
	}
}