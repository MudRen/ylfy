// suodi.c ����������.����

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����������.����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 50)
		return notify_fail("���ɱ���ķ���򲻹���\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ�Ѿ���æ�����ˣ��ŵ������ɢ�\n");

	if((int)me->query_skill("feitian-yujianliu",1) < 300)
		return notify_fail("��ķ�������������Ϊ����, ����ʹ����һ���� !\n");

	if((int)me->query_skill("blade", 1) < 300)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");

	if ( me->query_skill_mapped("force") != "shayi-xinfa")
		return notify_fail("����뼤��ɱ���ķ�����ʹ�á����񡹣�\n");
	if( (int)me->query("neili") < 5000  )
		return notify_fail("�������������\n");

	msg = HIG "$N��ͼ����$n����ͻȻ�ӿ죬�Գ���������$n������Χ,��ͬ����������һ�㡣\n";

	if( (random(me->query("xyzx_sys/level")) + 1) > (int)target->query("xyzx_sys/level")/2 )
	{
		msg += HIW " ���$p��$P�����Լ��Ĺ�����Χ��������һ����\n" NOR;
		target->start_busy( (int)me->query_skill("feitian-yujianliu",1) / 100 + 2 );
	}
	else
	{
		msg += HIC"����$p������$P����ͼ��ȫ�����ˣ��ӿ������صĹ�����Χ��\n"NOR NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	if ((int)me->query_skill("feitian-yujianliu",1) > 200)
	{
		if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
		{
			attack_time = (int)me->query_skill("feitian-yujianliu", 1) / 100;
			if(attack_time>50) attack_time=50;
			msg = HIY "�� ������! ��$Nʹ�����ٵ��յ���,�ɼ��ٵ��յ�������������,������$n��ƽ��������\n";
			target->start_busy(1);
			message_vision(msg, me, target);
			for(i = 0; i < attack_time; i++)
			{
				me->add("neili", - 300);
				msg = HIM "$N��ʤ׷��! �������޾���ӣ���У������һ��������\n" NOR;
				COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			}
		}
		me->start_busy(3);
	}
	return 1;
}

