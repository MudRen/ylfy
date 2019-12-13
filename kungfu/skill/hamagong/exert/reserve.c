// reserve.c ��󡹦������ת

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	object weapon;
	int skill;

    if( target != me )
		return notify_fail("��ֻ���ø�󡹦�������Լ���ս������\n");
	
	if( (int)me->query_skill("hamagong", 1) < 40 )
		return notify_fail("��ĸ�󡹦������죬���ᾭ����ת��\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("�������������\n");

	if( (int)me->query_temp("hmg_dzjm") || me->query_temp("powerup") )
		return notify_fail("���Ѿ���ת��������ս�����ˡ�\n");

	skill = me->query_skill("hamagong",1);
	message_vision( HIR "$N����˫�ֳŵص��������˾�������ʱ��Ϣ������������������\n" NOR, me);

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
	tell_object(me, HIY "��˫��һ�ţ�һԾ���𣬽������ջص��\n");
}
}