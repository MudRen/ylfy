#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	me->clean_up_enemy();
	target = me->select_opponent();
	skill = me->query_skill("dugu-jiujian",1);
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ء�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	if( skill < 200)
		return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ء���\n");
	if( me->query("neili") < 500 )
		return notify_fail("��������������޷����á�����ء���\n");
	msg = HIC "$N�ڽ�â�������˶��¾Ž���Ҫ�죬һ�С�"HIG",�����"HIC"�����Ķ�����ǿ��Ľ���������ֱ��У�\n";
	message_vision(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword");
	dp = target->query_skill("unarmed");
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$n��ʱ������ǰһ��������һ������";
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
		msg = "����$n������$N�Ľ��������̽�����" + weapon2->name() + "��÷��겻͸��ʹ$N�ġ�����ء�û�������á�\n"NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}

