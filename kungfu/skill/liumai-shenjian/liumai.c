// liujian.c ������   �����뷢

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����뷢ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�������뷢��\n");

	if( (int)me->query_skill("liumai-shenjian", 1) < 150 )
		return notify_fail("��������񽣲�����죬����ʹ�������뷢��\n");
	if( me->query_skill("unarmed") < 150 )
		return notify_fail("����ָ���ϵ����費�����޷�ʹ���������ڡ�\n");
	if( me->query_skill("dodge") < 150 )
		return notify_fail("�����Ṧ�ϵ����費�����޷�ʹ���������ڡ�\n");
	if( me->query("max_neili") < 800||(int)me->query("neili", 1) < 1500 )
		return notify_fail("����������̫��������ʹ�������뷢��\n");

	message_vision(HIW"$N���Ծ��,ʹ���������񽣵���߾����������ڡ�\n" + HIC"������⼲�����������$n������\n"NOR, me, target);
	msg = CYN "$N����ԴԴӿ�������̡��������г塢�س塢�ٳ塢������������,$n������ס��\n��ʱ������������\n"NOR;
	me->add("neili", -500);

	if (random(me->query_skill("unarmed")) > random(target->query_skill("force")) )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		damage = (int)me->query_skill("unarmed") + me->query_skill("force");
		damage = damage + random(damage);

		target->receive_damage("qi", damage*3, me);
		target->receive_wound("qi", damage*2, me);
		//if(!environment(target)->query("fight_room"))
		//target->receive_wound("qi", damage*8);
		me->add("neili", -1500 );
		me->add("max_neili", -1);
		msg += HIR"���$n��$N�Ľ������У�����[��]���³�һ����Ѫ�������絾����һ�����ɳ�������\n"NOR;

	}
	else
	{
		me->start_busy(6);
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
	}
	message_vision(msg, me, target );

	return 1;
}

