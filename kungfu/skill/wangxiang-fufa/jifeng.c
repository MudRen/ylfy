// jifeng.c ����ն

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target, weapon2;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("wangxiang-fufa",1);

	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("wangran-xinfa", 1) < 50)
		return notify_fail("��ı����ķ���򲻹����޷�ʹ�á�\n");
	if ((int)me->query("shen") < 0)
		return notify_fail("�����������̫���ˣ��޷�������־��\n");

	if ((int)me->query_skill("shuiyue", 1) < 50)
		return notify_fail("��ı����Ṧ��򲻹����޷�ʹ�á�\n");
	if( skill < 50)
		return notify_fail("������븫���ȼ�����, ����ʹ�ü���ն��\n");

	if( me->query("neili") < 500 )
		return notify_fail("��������������޷����ü���ն��\n");

	msg = HIW "$NǱ�����븫��֮"HIG"����ն"HIW"������$n"HIW"��ȥ��\n"NOR;
	message_vision(msg, me, target);

	ap = me->query_skill("axe",1) + skill;
	dp = target->query_skill("force",1) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-150);
		msg = HIY"���һ������, $n"HIY"��ʱ��������һʹ��"HIR"��Ѫ"NOR""HIY"���������\n"NOR;
		message_vision(msg, me, target);
		neili_wound = 300 + me->query_skill("axe");
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(2);
		me->start_busy(1+random(1));

		if  ((me->query("family/family_name") == "����������") && (random(skill) >= 150) && (objectp(weapon2 = target->query_temp("weapon"))))
		{
			weapon2->move(environment(me));
			msg = YEL"$n����һ�飡���б��в��������ĵ����˵��ϣ�\n"NOR;
			message_vision(msg, me, target);
		}
	}
	else
	{
		if(userp(me))
			me->add("neili",-100);
		msg = RED "����$n������������$N�Ĺ�����\n"NOR;
		message_vision(msg, me, target);
		me->start_busy(4);
	}

	return 1;
}
