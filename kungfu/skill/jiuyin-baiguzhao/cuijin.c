// cuijin.c  �����׹�צ���ݽ��ƹǡ�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage, damage1, qi;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ݽ��ƹǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ݽ��ƹǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 500 )
		return notify_fail(WHT"��ľ����׹�צ������죬��ʹ�������ݽ��ƹǡ���\n"NOR);

	if( (int)me->query_skill("force", 1) < 500 )
		return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á��ݽ��ƹǡ��������Լ��ľ�����\n"NOR);

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�����������ˡ�\n");

	msg = HIC "$Nһ����Х������$n��ת��Ȧ������ʩչ�����ݽ��ƹǡ���˫צ�����ֱ��$nǰ�ء�\n"NOR;
	if ( target->query("qi") < me->query("max_qi") )
		qi = target->query("qi");
	else
	{
		if ( target->query("qi") < me->query("qi") )
			qi = target->query("qi");
		else
			qi = me->query("qi");
	}
	damage1 = qi / 3;
	damage = damage1 + random(damage1*2);
	if (random(me->query("xyzx_sys/level")) > random(target->query("xyzx_sys/level")))
	{
		if (random(me->query("neili")) > random(target->query("neili")))
		{
			me->start_busy(3);
			target->receive_damage("qi", damage/2, me);
			target->receive_wound("qi", damage/2, me);
			target->apply_condition("jy_poison",10);
			me->add("neili", -1000);
			msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
			target->start_busy(3);
		}
		else
		{
			me->start_busy(3);
			target->receive_damage("qi", damage/10, me);
			target->receive_wound("qi", damage/10, me);
			me->add("neili", -1000);
			msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض���,ֻ��$n��ǰ������һ��Ѫ�ۣ�����\n"NOR;
			target->start_busy(1);
		}
	}
	else
	{
		me->start_busy(3);
		me->add("neili", -1000);
		msg += HIY"����$p���з��������Ų�æ,ж����$P��˫צ��\n"NOR;
	}
	message_vision(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
