#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("һ����ɢֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ����ܶ��ˣ�\n");

	if( (int)me->query_skill("cuixin-zhang", 1) < 500 )
		return notify_fail("��Ĵ����Ʋ�����죬����ʹ�á�һ����ɢ����\n");

	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("��һ����ɢ��ֻ�������ɴ��˲���ʹ�á�\n");

	msg = HIM "$N��һҡ��һ�С�һ����ɢ����Ȼ��������$n�����ϡ�\n"NOR;

	if( random( me->query_skill("cuixin-zhang",1)+me->query_skill("unarmed",1) ) > (me->query_skill("unarmed",1)*2)/3 )
	{
		msg += HIR "$p������������$N�������ϼ���Ѩ������ʱ�������á�\n" NOR;
		target->start_busy( (int)me->query_skill("cuixin-zhang") / 40 );
		me->add("neili", -500);
	}
	else
	{
		me->start_busy(2);
		me->add("neili",-300);
		msg += HIC "$p������$N����ʽ��϶�����˹�ȥ��\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

