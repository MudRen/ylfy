// meng.c ��Ҷ����衸���Ρ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á����Ρ���\n");

	if( (int)me->query_skill("biye-wu", 1) < 40 )
		return notify_fail("��ı�Ҷ����費����죬����ʹ�á����Ρ���\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 30 )
		return notify_fail("��ı����ķ������ߣ��������������˵С�\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("����������̫��������ʹ�á����Ρ���\n");

	msg = CYN "$NĬ��ھ���ʹ����Ҷ�����֮�����Ρ�����������������$n��\n"NOR;

	if (random(me->query_skill("unarmed")) > target->query_skill("force")/3 || random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
	{

		damage = (int)me->query_skill("force") + me->query_skill("unarmed") *3;
		damage = damage/3 + random(damage/3);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -damage/3);

		msg += HIR"���$n��$N������һ����ǰһ�ڣ����㵹���ۿ���Ҫ���������ˣ�\n"NOR;

	}
	else
	{
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(4);

	return 1;
}