// kuangda.c �컨ʮ����������򡹾�

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
		return notify_fail("����򡹾�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query_skill_mapped("sword") != "luohua-jian")
		return notify_fail("����뼤���ۺ컨ʮ�������ݲ���ʹ�á���򡹣�\n");
	if((int)me->query_skill("honghua-shengong",1)<300)
		return notify_fail("��ĺ컨�񹦲�����񣬲���ʹ�á���򡹾���\n");
	if( (int)me->query_skill("luohua-jian", 1) < 450 )
		return notify_fail("��ĺ컨ʮ������������죬����ʹ�á���򡹾���\n");

	msg = HIY "$Nʹ���컨ʮ����������򡹾�����ʽ��Ȼ��죬��������Է���\n";
	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		attack_time = random((int)me->query_skill("luohua-jian", 1) / 30);
		if(attack_time < 1) attack_time = 1;
		if(attack_time > 50) attack_time = 50;
		me->add_temp("lianzhao", attack_time);
		msg += CYN " ���$p��$P���˸����ֲ�����\n" NOR;
		for(i = 0; i < attack_time; i++)
		{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}

		me->start_busy(2);
		me->add("neili", -100*attack_time);
		me->delete_temp("lianzhao");
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
