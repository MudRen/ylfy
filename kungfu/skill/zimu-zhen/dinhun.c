// ���� ��ĸ�����⼼

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ���־��㱣��ŵ�������.\n");

	if( (int)me->query_skill("zimu-zhen", 1) < 30 )
		return notify_fail("�����ĸ�뷨������죬����ʹ�á����꡹��\n");

	msg = HIG "$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ�\n"NOR;

	me->start_busy(1);
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += HIR " ���$p��$P�ġ����꡹������ţ�˲����־��ʼ�Ժ�������\n" NOR;
		target->start_busy( (int)me->query_skill("zimu-zhen") / 20 );
	}
	else
	{
		msg += "����$p��ǧ��һ��֮������������һ����\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
