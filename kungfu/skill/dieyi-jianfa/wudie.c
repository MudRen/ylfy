// ��������� wudie.c

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

	if( !target || !target->is_character() ||!me->is_fighting(target) )
		return notify_fail("�������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("dieyi-jianfa", 1) < 80 )
		return notify_fail("��ĵ�����������죬����ʹ�õ����������\n");

	msg = HIC "$Nʹ��������֮�������������ʽ����쳣Ϭ����\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/50 )
	{
		attack_time = random((int)me->query_skill("dieyi-jianfa", 1) / 45);
		if(attack_time > 7)
		{
			attack_time = 12;
			msg += RED " ���$p��$P�ҽ��뷢���˸���ֻ����\n" NOR;
		}
		else
		{
			msg += RED " ���$p��$P����"+attack_time+"����\n" NOR;
		}
		if(attack_time < 1) attack_time = 1;
		for(i = 0; i < attack_time; i++)
		{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		message_vision(msg, me, target);
		if(attack_time < 7)
			me->start_busy(2);
		me->add("neili", -200);
	}
	else
	{
		msg += MAG"����$n������$N����ͼ����û���ϵ���\n" NOR;
		me->start_busy(3);
		message_vision(msg, me, target);
	}
	return 1;
}
