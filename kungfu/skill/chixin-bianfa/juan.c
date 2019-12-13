// juan.c ������
#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("juan") )
		return notify_fail("���Ѿ���ʹ�÷������ˡ�\n");
	skill = me->query_skill("chixin-bianfa",1);

	if( !(me->is_fighting() ))
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("shen") < 0)
		return notify_fail("�����������̫���ˣ��޷�������־��\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	if( skill < 50)
		return notify_fail("��ĳ��ı޷��ȼ�����, ����ʹ�÷����ƣ�\n");
	if ((int)me->query_skill("wangran-xinfa", 1) < 50)
		return notify_fail("��ı����ķ���򲻹����޷�ʹ�á�\n");
	if ((int)me->query_skill("shuiyue", 1) < 50)
		return notify_fail("��ı����Ṧ��򲻹����޷�ʹ�á�\n");
	if( me->query("neili") < 50 )
		return notify_fail("��������������޷�ʹ�÷����ƣ�\n");

	msg = HIW "$NĬ��ھ�������ʩչ�����ƾ���. \n"NOR;
	message_vision(msg, me);
	if (me->query("family/family_name") == "����������")
	{
		(dp = target->query_skill("parry") / 3);
	}
	else
	{
		(dp = target->query_skill("parry") / 3 * 2);
	}
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp || random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = WHT"$N��������"+ NOR+weapon->name()+ WHT"����$n, $n"WHT"��ʱ������ǰһ��������һ�飬" NOR+ weapon2->name() +WHT"���ֶ�����\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		me->start_busy(1+random(1));
	}
	else
	{
		msg = RED"����$n"RED"�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
		me->start_busy(1+random(2));
	}
	message_vision(msg, me, target);

	return 1;
}
