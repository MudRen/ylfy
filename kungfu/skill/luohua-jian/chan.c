#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if( (int)me->query_skill("luohua-jian", 1) < 150 )
		return notify_fail("��ĺ컨ʮ������������죬����ʹ�á������־���\n");

	msg = HIG "$Nʹ���컨ʮ�����������־�����������������ͼ����$n�Ĺ��ơ�\n";

	me->start_busy(1);
	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/4 )
	{
		msg += HIR " ���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("luohua-jian") / 16 );
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	me->add("neili", -100);
	message_vision(msg, me, target);

	return 1;
}

