// feilong.c  ���콣�����������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"װ��������ʹ�á������������\n"NOR);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ((int)me->query_skill("kuangfeng-jian", 1) < 200 )
		return notify_fail(WHT"����콣������죬ʹ�����������������\n"NOR);
	if ((int)me->query_skill("huashan-neigong", 1) < 200 )
		return notify_fail(RED"�㻪ɽ�ڹ���򲻹���ʹ�����������������\n"NOR);
	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
	if ((int)me->query("neili") < 400)
	{
		return notify_fail(HIC"����������������û�ܽ������������ʹ�꣡\n"NOR);
	}
	msg = HIC "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��\n"NOR;
	if ( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		me->start_busy(3);
		target->start_busy(random(2));
		damage = target->query("qi");
		target->receive_damage("qi", damage/3);
		target->receive_wound("qi", damage/3);
		msg += HIC"$n��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����\n"NOR;
		me->set("neili", me->query("neili")/2);
	}
	else
	{
		me->start_busy(2);
		me->set("neili", 100);
		msg += HIY"����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�\n"NOR;
	}
    weapon->move(environment(me));
	message_vision(msg, me, target );
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}