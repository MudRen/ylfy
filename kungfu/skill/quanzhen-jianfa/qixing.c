// qixing. ���Ǿ�����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon = me->query_temp("weapon");
	int damage;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Ǿ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("quanzhen-jianfa", 1) < 90 )
		return notify_fail("���ȫ�潣������������ʹ�������Ǿ�������\n");

	if (!weapon || weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "quanzhen-jianfa")
		return notify_fail("�������޷�ʹ�����Ǿ�������\n");

	if ( (int)me->query("neili") < 200)
		return notify_fail("��������������޷�ʹ�����Ǿ�������\n");

	msg = HIY"\n$Nһ����Х��һ�����н�����ʱ�γ�һ����Ļ����籩���ѹ��$n������$n����֮�䣬��Ļ�зɳ��߶亮�ǣ������ǰ�����$n��\n"NOR;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		msg +=HIR"$n������������Ȼ�н���\n"NOR;
		damage = 3*(int)me->query_skill("quanzhen-jianfa");
		damage = damage / 2 + random(damage / 2);
		if (damage > target->query("neili") / 10)
			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		if( damage < 40 ) msg += HIR"$n���������������ϵ�����Ѫ��\n"NOR;
		else if( damage < 80 ) msg += HIR"$n�����߽�����Ѫ���������\n"NOR;
		else msg += HIR"$n���ۡ��Ŀ��һ������������ߵ�Ѫ����\n"NOR;
		message_vision(msg, me, target);
	}
	else
	{
		msg += HIC"$n�鼱֮����󼤷ɣ����ſ�£����������������һ����\n"NOR;
		message_vision(msg, me, target);
	}
	me->add("neili", -180);
	me->start_busy(2);

	return 1;
}

