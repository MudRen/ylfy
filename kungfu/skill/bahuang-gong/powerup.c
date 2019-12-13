#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("��ֻ���ð˻����Ϲ��������Լ���ս������\n");
	if( (int)me->query("neili") < 100  )
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");
	skill = me->query_skill("force");
	if (me->query_skill("bahuang-gong",1) < 60) 
		return notify_fail("��İ˻������񹦻�������졣\n");
	me->add("neili", -100);
	message_vision( HIR "$N����Ϣ��������˻�����Ψ�Ҷ��𹦣�ֻ��һ��������������\n" NOR, me);
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
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), 600);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}
void remove_effect(object me, int amount)
{
	if (!me)   return;
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
		tell_object(me, "��İ˻�����Ψ�Ҷ���������ϣ��������ջص��\n");
	}
}

