// juehu.c ���������֡�������perform
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage,l_temp;
	string msg;

	int busy_time,busy_time1,pfm_time,pfm_time1;
	busy_time=3;   //perform��æʱ�����
	busy_time1=2;  //�ɹ����ֵ�æʱ�����
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���˵�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á��������񹦣�\n");

	if( (int)me->query_skill("juehu-shou", 1) < 100 )
		return notify_fail("��Ļ�צ�����ֲ�����죬����ʹ�á���������\n");

	if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
		return notify_fail("��������������ߣ������á����������˵С�\n");

	if( (int)me->query("shen") < -1000 )
		return notify_fail("��а��̫�أ��޷�ʹ������������ʽ��\n");

	if(me->query("juehu_nouse"))
		return notify_fail("����Ϣ�޷�����������Ѩ������ʹ������������ʽ��\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("����������̫��������ʹ������������ʽ��\n");

	if( (int)me->query_condition("juehu_busy"))
		return notify_fail("��Ԫ�����ˣ�����û������ʹ������������ʽ��\n");


	msg = BLU "$NĬ���񹦣���ɫ�׵����ˣ�ͻȻʹ����צ�����ֵ����һ��������������ͼ������$n�������¡�\n"NOR;

	pfm_time=(int)busy_time-(me->query("juehu-shou",1)+me->query("yinyun-ziqi",1))*(1+busy_time)/200*busy_time;
	pfm_time1=busy_time1+(int)(me->query("juehu-shou",1)+me->query("yinyun-ziqi",1))*(1+busy_time)/200*busy_time;
	if (random(me->query_skill("force",1)) > target->query_skill("force",1)/2 )
	{
		me->start_busy(pfm_time);
		target->start_busy(random(pfm_time1));

		damage = (int)me->query_skill("juehu-shou", 1);
		damage = damage + random(damage)/2;

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		target->receive_damage("jing", damage/2);
		target->receive_wound("jing", damage/3);
		me->add("neili", -damage/6);
		msg += RED"���$Nһ�����У�$nֻ�е�����һ���ʹ�����ھ�Ԫ������й����ʱ������֫���������Ȳ�ͣ������\n"NOR;

	}
	else
	{
		me->start_busy(random(pfm_time));
		l_temp=80-(int)me->query_skill("yinyun-ziqi", 1)/10;
		me->add("neili", -l_temp);
		msg += CYN"����$p������$P�ĺݶ���ͼ�����������������㿪��$P������һ����\n"NOR;
	}
	message_vision(msg, me, target );
	if (damage>200 )
	{
		me->add("shen", -damage);
		target->apply_condition("juehu_hurt",(int)(500*target->query("age")));
		me->apply_condition("juehu_busy",(int)(100*me->query("age")));
		me->add("max_neili", - (20 + random(20)));
		if (target->query("gender")== "����")
		{
			target->set("gender","����");
			target->set("genderbak","����");
			message_vision(HIW"$NͻȻ���ĵ����ڵľ�Ԫ����ʧ�ʾ�������һ���ѹ���֪���Լ���һ��ʱ�䲻���л�������!\n"NOR,target);
		}
		else
		{
			if (target->query("gender")== "Ů��")
				message_vision(HIW"$N����һ�����У�������������ŭ����$n����һŮ��֮��Ҳ�ô�����������\n"NOR,target,me);
			else
				message_vision(HIW"$N��Ȼ����$n��Ҫ�������о��������ᣬ�ƺ�����Ҫ������!\n"NOR,me,target);
		}
		target->kill_ob(me);
	}
	return 1;
}
