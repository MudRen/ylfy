// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("guiyuan-dafa", 1) < 20)
		return notify_fail("��Ĺ�Ԫ����Ϊ��������\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIY "��ȫ����ɣ���������ʼ�˹���\n" NOR);
	message("vision",
		HIW + me->name() + "����������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("jing", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
      me->start_busy(4);

	return 1;
}
