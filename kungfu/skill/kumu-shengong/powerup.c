// powerup.c ��ľ�񹦼���
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("��ֻ���ÿ�ľ���������Լ���ս������\n");
	if( (int)me->query("neili") < 100  )
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if (me->query_skill("kumu-shengong",1) < 100)
		return notify_fail("��Ŀ�ľ�񹦻�������졣\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);
	
	message_vision( BOLD "$N΢һ���������ľ�񹦣���ɫ��Ȼ��Ʊ�ò�����\n" NOR, me);
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
		tell_object(me, BOLD"��Ŀ�ľ��������ϣ��������ջص��\n"NOR);
	}
}
