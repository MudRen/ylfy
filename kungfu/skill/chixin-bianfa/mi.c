// mi.c ���ı޷����λ�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���λ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("shen") < 0)
		return notify_fail("�����������̫���ˣ��޷�������־��\n");

	if( (int)me->query_skill("chixin-bianfa", 1) < 40 )
		return notify_fail("��ĳ��ı޷�������죬����ʹ�����λ���\n");
	if ((int)me->query_skill("wangran-xinfa", 1) < 50)
		return notify_fail("��ı����ķ���򲻹����޷�ʹ�á�\n");
	if ((int)me->query_skill("shuiyue", 1) < 50)
		return notify_fail("��ı����Ṧ��򲻹����޷�ʹ�á�\n");

	msg = HIW "$Nʹ�����λ�������ͻȻ¶���������Ц��$n"HIW"ֻ�����������ĺ����������Լ���\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 || random(me->query("whip")) > target->query("dodge")/3 )
	{
		attack_time = random((int)me->query_skill("chixin-bianfa", 1) / 50);
		if (me->query("family/family_name") == "����������")
		{
			if(attack_time < 4)
				attack_time = 4;
			if(attack_time > 14)
				attack_time = 14;
		}
		else
		{
			if(attack_time < 2)
				attack_time = 2;
			if(attack_time > 7)
				attack_time = 7;
		}
		msg += MAG "���$n"MAG"��$N���������Σ���ʱ�����㱣�\n" NOR;
		message_vision(msg, me, target);
		for(i = 0; i < attack_time; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		if (me->query("family/family_name") == "����������")
		{
			me->start_busy(2+random(1));
			me->start_busy(1+random(2));
			target->start_busy(1+random(4));
		}
		else
		{
			me->start_busy(4+random(2));
			target->start_busy(1+random(2));
		}
		me->add("neili", -100);
	}
	else
	{
		msg += RED"����$n"RED"������$N����ͼ����ס�����ǡ�\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2+random(2));
	}

	return 1;
}
