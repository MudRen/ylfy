#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��"+HIC"����"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("adai-quanfa", 1) < 500 )
		return notify_fail("��İ���ȭ����������������ʹ�á�"+HIC"����"NOR+"����\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("������������ˡ�\n");

	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");

	msg = HIC"$N���һ����ʹ������ȭ�������һ�С��װ��ģ��Ұ������ˡ���˫���������$n������ȥ������ \n"NOR;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/3)
	{
		me->start_busy(1);
		target->start_busy(20);

		damage = me->query_skill("unarmed") + me->query_skill("force");
		damage = damage + random(damage)*2;

		target->receive_damage("qi", damage*4);
		target->receive_wound("qi", damage*4);
		me->add("neili", -damage-500);
		msg += HIR "$n����һ����Σ�����$N�Ļ������е�����Ҫ����Ҫ����\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		return 1;

	}
	else
	{
		me->start_busy(5);
		me->add("neili",-100);
		msg += HIG"$n˵��:�����������书��ô�����˵�����,�ҿ�������֮����,ͷһ��,����һ�صĿ�ˮ,�ӳ���$N��һ�С�\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}


