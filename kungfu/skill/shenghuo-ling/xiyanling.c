// xiyanling.c ʥ��������桹��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	else if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("���ֲ�û��ʹ��������\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if( (int)me->query_skill("shenghuo-ling", 1) < 40 )
		return notify_fail("���ʥ���������죬ʹ���������桹�\n");

	msg = HIG "$Nʹ��ʥ��������桹������������ȵ���ʽ��ͼ����$n���еı�����\n";

	me->start_busy(1);
	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		msg += HIR " ���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("taiji-jian") / 40 +2 );
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
