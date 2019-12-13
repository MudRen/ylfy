#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ʹĪ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ����ܶ��ˣ�\n");

	if( (int)me->query_skill("damo-force", 1) < 600 )
		return notify_fail("��Ĵ�Ħ�񹦲�����죬�޷�ʩչ���ơ�\n");

	if( (int)me->query_skill("dabei-zhang", 1) < 600 )
		return notify_fail("��Ĵ��Ʋ�����죬����ʹ�á���ʹĪ������\n");

	msg = HIB "$N����¶��һ˿��ʹ�����飬��������һ�������ӷ�,\n"NOR;
	msg += HIB "˫�ֻ������Ƴ�������ƽ����һ�У����ǿ�����һ˿\n"NOR;
	msg += HIW "�������������Ǵ�������������ʹĪ������\n"NOR;

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += HIW "$p��ͼͻ��$N�Ĺ�����Χ�����Ǳ�$N���Ʒ�ܵĺ�����·��\n" NOR;
		target->start_busy( random(4));
		target->apply_condition("no_perform", 10);
		me->add("neili", -500);
	}
	else
	{
		me->start_busy(2);
		me->add("neili",-300);
		msg += HIC "$pһ�ۿ�����$N�����������˹�ȥ��\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

