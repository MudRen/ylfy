//kuihuawudi �����޵�

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("��ֻ�ܶ��Լ���["+HIR+"�����޵й�"+NOR+"]\n"NOR,);
	
	if ((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("��Ŀ����ķ�̫���ˡ�\n");
	
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if(time() - me->query("powerupxb") <= 0)
		return notify_fail("���Ѿ����˹����ˡ�\n");
	
	if (!me->query("breakup"))
		return notify_fail("���ζ�����δͨ,�޷�ʹ��["+HIR+"�����޵й�"+NOR+"]\n"NOR,);

	if(!me->query("xy_huiyuan"))
		return notify_fail("ֻ�л�Ա����ʹ��["+HIR+"�����޵й�"+NOR+"]\n"NOR,);
	
	skill = me->query_skill("force",1);
	
	me->add("neili", -500);
	me->receive_damage("qi",20);
	
	message_vision(HIW"$NͻȻ���� ��!��!��!��!��Ц����,���������һ��[ȫ��������ȣ�Ʈ����ȥ��ֱ������]��\n" NOR, me);
	
	me->add_temp("apply/attack", skill/5);
	tell_object(me,HIR"��Ĺ����������!\n"NOR);
	me->add_temp("apply/dodge", skill/5);
	tell_object(me,HIR"��ķ����������!\n"NOR);
	me->set_temp("powerup", 1);
	me->set("powerupxb",time()+skill);
	//��������
	if(skill = me->query_skill("kuihua-xinfa",1))
	{
		me->add_temp("apply/strength",skill/25);
		tell_object(me,HIG"������������!\n"NOR);
		me->add_temp("apply/dexerity",skill/25);
		tell_object(me,HIG"����ٶ������!\n"NOR);
		me->add_temp("apply/constitution",skill/25);
		tell_object(me,HIG"��ĸ��������!\n"NOR);
		me->add_temp("apply/intelligence",skill/25);
		tell_object(me,HIG"������������!\n"NOR);
	}
	
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,me->query_skill("force",1)/5:),me->query_skill("force",1));
	
	if( me->is_fighting() )
		me->start_busy(4);
	return 1;
}

void remove_effect(object me, int amount)
{
	int skill;

	skill = me->query_skill("force",1);
    if (!me) return;
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	//���Ի�ԭ
	if(skill = me->query_skill("kuihua-xinfa",1))
	{
		me->add_temp("apply/strength", -(amount/25));
		me->add_temp("apply/intelligence", -(amount/25));
		me->add_temp("apply/constitution", -(amount/25));
		me->add_temp("apply/dexerity", -(amount/25));
	}
		me->delete_temp("apply/strength");
		me->delete_temp("apply/intelligence");
		me->delete_temp("apply/constitution");
		me->delete_temp("apply/dexerity");
		me->delete_temp("apply/attack");
		me->delete_temp("apply/dodge");
	//ɾ��ʶ�����
	me->delete("powerupxb");
	
	tell_object(me, "���["+HIR+"�����޵й�"+NOR+"]������ϣ��������ջص��\n");
}

