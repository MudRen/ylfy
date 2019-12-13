// tianwai.c ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	int damage;
	object weapon, target;
	int skill, ap, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("yuxiao-jianfa",1);

	if( !(me->is_fighting() ))
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( me->query_skill("bibo-shengong",1) < 120)
		return notify_fail("��ı̲��񹦵ȼ�����, ����ʹ�á�������������\n");

	if( skill < 90)
		return notify_fail("������｣���ȼ�����, ����ʹ�á�������������\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����á�������������\n");

	msg = HIC "$Nһ����Х����������������һ����������������һʽ��������������"+weapon->name()+"������ֹ����Ӱ��ҹĻ������$n��\n";

	ap = me->query_skill("sword",1) + skill;
	dp = target->query_skill("force",1) / 2;
	if( dp < 1 )
		dp = 1;

	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		target->start_busy( (int)me->query_skill("yuxiao-jianfa") / 30 + 1);


		damage = damage + me->query_skill("bibo-shengong", 1);
		damage = damage + me->query_skill("yuxiao-jianfa", 1);

		target->receive_damage("qi", damage*5);
		target->receive_wound("qi", (damage/2)*5);
		me->add("neili", -damage);
		msg = "$n��ʱ������ǰ�����������˫��������������֪����һ���ʹ������һ�㣡\n" NOR;
		me->start_busy(2);
	}
	else
	{
		msg = "����$n���ľ��������ֻ�������$N������Ʋ��һ�ߡ�\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}

