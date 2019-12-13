// recoverjing.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭�ָ�������\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹���\n");

	if(target == me)
		return notify_fail("��û��Ϊ�Լ��˹���������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIR "$N�����Ԫ�󷨣���$n����������һ����������������$n������....\n\n"
		"���˲��ã�$N����һ�������ջ�˫�ƣ�$n�������ö��ˡ�\n" NOR,
		me, target );

	target->receive_curing("jing", 10 + (int)me->query_skill("force")/3 );
	target->add("jing", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));

	me->add("neili", -150);
	me->set("jiali", 0);
                me->start_busy(5);
                target->start_busy(5);
	return 1;
}
