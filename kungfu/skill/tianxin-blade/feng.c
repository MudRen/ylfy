#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	me->clean_up_enemy();
	target = me->select_opponent();
	skill = me->query_skill("tianxin-blade",1);
	if( !(me->is_fighting() ))
		return notify_fail("���⡹�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("���⡹�־�ֻ��ͨ���촫�˲���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	if( skill < 200)
		return notify_fail("������е����ȼ�����, ����ʹ�á��⡹�־���\n");
	if( me->query("neili") < 500 )
		return notify_fail("��������������޷����á��⡹�־���\n");
	if (me->query_temp("perform"))
		message_vision(HIC"$N����һ����ʩչ�����е������⡹�ֵ��������е������ŶԷ�������ȥ��\n"NOR, me, target);

	damage = 10 * me->query_skill("blade");
	ap = skill+me->query_skill("blade",1);
	dp = target->query_skill("parry",1) + target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$n��ʱ����һ�ɴ�����$N���ϴ�����һ�����������һ�飬����";
		msg += weapon2->name();
		msg += "���ֶ�����\n" NOR;
		target->receive_damage("qi", damage);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me))
			me->add("neili",-30);
		msg = "����$n������$N����ͼ�����̽�����" + weapon2->name() + "��÷��겻͸��ʹ$N�ġ��⡹�־�û�������á�\n"NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}


