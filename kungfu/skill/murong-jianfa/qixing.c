// qixing.c /kungfu/skill/murong-jianfa/qixing.c ��ת����
// update by beyond 97.9.2

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ת����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("murong-jianfa", 1) < 100 )
		return notify_fail("��Ľ�ת���ǻ�δ���ɣ�����ʹ�ã�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������㣬����ʹ�ý�ת���ǣ�\n");

	if( (int)me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�������������죬����ʹ�ý�ת���ǡ�\n");

	msg = HIY "\n$N��Ȼ����һת���������������棬ֻ���߶佣���������ֱ�Ϯ��$n��" +
	      "�ߴ�ҪѨ��\n"NOR;

	if ( random(me->query_dex(1)) > (int)target->query_dex(1)*2/3 )
	{
		msg += HIR"\n$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ��������϶�\n" +"���߸�Ѫ��ģ����Ѫ������\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -100);
	}

	else
	{
		msg += HIG"\n$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}

	if (random(me->query_skill("sword")) > target->query_skill("parry")/3 )
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword");
		damage = damage*5/2 + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		target->add("neili", -random(damage));
		me->add("neili", -100);

		if( damage < 300 ) msg += HIC"\n���$n��ɫ��òҰף������������˺ü�����\n"NOR;
		else if( damage < 400 ) msg += HIM"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
		else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
		else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;

	}

	else
	{
		me->start_busy(2);
		msg += HIG"\n$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
