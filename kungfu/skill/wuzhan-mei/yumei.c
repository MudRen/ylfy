// �꼤÷������� ��չ÷���⼼
// by hem
// yumei.c perform wuzhan-mei
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	object weapon;
	object obj;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���꼤÷������㡹ֻ�ܶԶ���ʹ�á�\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á��꼤÷������㡹��\n");

	if(me->query_skill("wuzhan-mei")<100)
		return notify_fail("�����չ÷������죬�������á��꼤÷������㡹��\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("���ֲ�û��ʹ��������\n");
	msg = HIC"$N���н�ббһ����ʩչ�����꼤÷������㡹����ƮƮѹס$n�ı�����\n"NOR;
	me->start_busy(1);
	if( random( me->query("xyzx_sys/level"))>random(target->query("xyzx_sys/level") ) )
	{
		msg +=HIC"ֻ����һ�����֮����$p�ı��о���$P���飬��м�籩��㷴����$p��\n" NOR;
		obj=target->query_temp("weapon");
		destruct(obj);
		damage = (int)me->query_skill("sword");

		damage = damage + random(damage/2)+200;

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/1);
		me->add("neili", -damage);

		msg += HIR"���$n�����ɵı�����м���У��������¾�����һ�㣡\n"NOR;
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	return 1;
}