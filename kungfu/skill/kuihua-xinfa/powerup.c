// powerup.c �����ķ�����

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	
	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	
	if( (int)me->query("neili")<200)
		return notify_fail("�������������\n");
	
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if(time() - me->query("powerupsb") <= 0)
		return notify_fail("���Ѿ����˹����ˡ�\n");
	
	if( (int)me->query_skill("kuihua-xinfa",1) < 50)
		return notify_fail("��Ŀ����ķ����������졣\n");
	
	if (!me->query("breakup"))
		return notify_fail("���ζ�����δͨ,�޷�ʹ��["+HIR+"�����ķ�����"+NOR+"]\n"NOR,); 	

	skill = me->query_skill("force",1);
	skill += me->query_skill("kuihua-xinfa",1);
	message_vision(HIC "$N����������ȣ�Ʈ����ȥ��ֱ�����̣�"HIW"�����ް������"HIC"��\n" NOR, me);
	
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->set("powerupsb",time()+skill);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
	
	if( me->is_fighting() )
		me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	me->delete("powerupsb");
	tell_object(me, "��Ŀ����ķ�������ϣ��������ջص��\n");
}
