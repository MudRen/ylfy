// lybf.c ��Ӣ��֮��Ӣ�ͷ�
// by victori
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int busy_time;
	int c,d;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����Ӣ�ͷס�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("luoying-shenjian", 1) < 200 )
		return notify_fail("�����Ӣ�񽣲�����죬����ʹ�á���Ӣ�ͷס���\n");

	if( (int)me->query_skill("qimen-wuxing", 1) < 100)
		return notify_fail("�������������Ϊ̫�ͣ�����ʹ�á���Ӣ�ͷס���\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("����������̫��������ʹ�á���Ӣ�ͷס���\n");

	msg = HIM "$N�����������֮�����󷨣�ʹ���һ�����Ӣ����֮����Ӣ�ͷס�������ֱ��$n��\n"NOR;

	//if( !target->is_killing(me) ) target->kill_ob(me);

	c=me->query_skill("jing")+me->query_skill("qimen-wuxing",1);
	c+=me->query_skill("sword",1)+me->query_skill("dodge",1);
	d=target->query_skill("jing")+me->query_skill("qimen-wuxing",1);
	d+=target->query_skill("dodge",1);
	if (random(c) > d/2 )
		//˫����sword/dodge,qimen-wuxing�뾫��ߵ;����ɹ���
	{
		me->start_busy(3);

		damage = (int)me->query_skill("luoying-shenjian") + (int)me->query_skill("qimen-wuxing");
		//(��Ӣ�񽣼���+��������)

		damage = damage/2 + random(damage/2);
		target->receive_damage("qi", damage);//��Ѫ����

		//�����busy��ʱ��=˫��qimen-wuxing����֮���10��С��4��4����㣩
		if(((me->query_skill("qimen-wuxing")-target->query_skill("qimen-wuxing"))/10)<4)
			busy_time=4;
		else busy_time=(int)((me->query_skill("qimen-wuxing")-target->query_skill("qimen-wuxing"))/10);
		//>10��10���㣬��������������wound
		if(busy_time>10)
		{
			target->receive_wound("qi", (busy_time-10)*10);
			busy_time=10;
		}

		target->start_busy(busy_time);

		me->add("neili", -150);
		//��ľ����д��
		me->add("jing", -100);

		msg += HIR"$n�޷�ʶ����������֮�������ڣ��������������$N�Ĺ��ƣ�Ȼ��֪���룡\n$N�������Ǵ̳�5��...\n"NOR;
		message_vision(msg, me, target);
		//�ٳ�5�е�д��
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);

	}
	else
	{
		me->start_busy(4);
		msg += CYN"����$p������$P����ͼ��$N�������������⡣\n"NOR;
		message_vision(msg, me, target);
	}


	return 1;
}
