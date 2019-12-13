//zhanqi.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("��ֻ�ܶ��Լ�ʹ�á�\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");
	if ( me->query_skill("shushan-force",1) < 100)
		return notify_fail("�����ɽ�ķ���������졣\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");
	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision( HIM "$N΢һ����������ɽ�ķ���һ�����ս���ӵ���ֱ���춥��\n" NOR, me);

	me->add_temp("apply/attack", skill);
	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/damage", skill);
	tell_object(me,HIG"����˺������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/dodge", skill);
	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/strength",skill);
	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/dexerity",skill);
	tell_object(me,HIG"����������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/constitution",skill);
	tell_object(me,HIG"��ĸ��������"+chinese_number(skill)+"��!\n"NOR);
	me->add_temp("apply/intelligence",skill);
	tell_object(me,HIG"������������"+chinese_number(skill)+"��!\n"NOR);

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
		tell_object(me, HIM"������ս��ѭ��һ������ϣ��������ջص��\n"NOR);
	}
}
