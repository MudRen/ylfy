// duanjia-sword.c  �μҽ� ����һ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("duanjia-sword", 1) < 450 )
		return notify_fail("��Ķμҽ���������죬����ʹ�á�\n");

	if( (int)me->query_skill("kumu-shengong", 1) < 510 )
		return notify_fail("��Ŀ�ľ����Ϊ�����ߡ�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("����������̫��������ʹ�á�����һ������\n");

	msg = HIM "$NһԾ����"NOR"��"HIM"����һ��"NOR"��"HIM"���һ��"YEL"����"HIM"�Ľ���"NOR"��"HIM"����$n"NOR"��\n"NOR;

	if (random(me->query_skill("sword")) > target->query_skill("force")/4 )
	{

		damage = (int)me->query_skill("force");
		damage = damage + (int)me->query_skill("sword");

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -300);
		msg += HIW"ֻ��$N�˽���һ"NOR"��"HIW"����$n"NOR","HIW"$nֻ��һ��������"HIR"��"HIW"����"NOR"��"HIW"��ͷһ��"NOR"��"HIR"��Ѫ"HIW"���������\n"NOR;;
		me->start_busy(1);
		message_vision(msg, me, target );
		COMBAT_D->report_status(target);

	}
	else
	{
		msg += NOR"����$n�͵������һԾ,������$N�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(2);
		message_vision(msg, me, target);
	}

	if(userp(target)) target->fight_ob(me);
	return 1;
}