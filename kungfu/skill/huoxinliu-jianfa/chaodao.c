// suodi.c ����������.����ֹ��

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
		return notify_fail("����������.����ֹ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 60)
		return notify_fail("���ɱ���ķ���򲻹���\n");
    if ( me->query_skill_mapped("blade") != "huoxinliu-jianfa")
		return notify_fail("����뼤���ۻ����������ݲ���ʹ�á�����ֹ�С���\n");
	if((int)me->query_skill("huoxinliu-jianfa",1) < 120)
		return notify_fail("�����Ȼ���������Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("blade") < 30)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");
	if( userp(me) && !me->query("feitian/chaodao"))
		return notify_fail("��ֻ��˵��,�������á�����ֹ�С���\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("�������������\n");

	msg = HIW "$N˫�ֽ���,���ֱ��ֵ�$n������,ʹ���������߷���ֹ������\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += HIW " ���$p��$Pһ�Ѽ�ס�������ã�\n" NOR;
		if (!target->is_busy())
		{
			target->start_busy( (int)me->query_skill("huoxinliu-jianfa",1) / 60 + 2 );
		}
	}
	else
	{
		msg += HIC"����$p������$P����ͼ���ջ������е�������\n"NOR NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	me->add("neili", - 60);
	if(!target->is_fighting(me)) target->fight_ob(me);
	if( me->query("xyzx_sys/level") > (int)target->query("xyzx_sys/level")/3 )
	{
		attack_time = (int)me->query_skill("huoxinliu-jianfa", 1) / 70;
		msg = HIC "$N˫�ֽ���,���ֱ��ֵ�����,ʹ���˸߷���ֹ������\n";
		target->start_busy(1);
		message_vision(msg, me, target);
		if ( attack_time < 1 ) attack_time = 1;
		if ( attack_time > 50 ) attack_time = 50;
		    me->add_temp("lianzhao", attack_time);
		for(i = 0; i < attack_time; i++)
		{
			msg = HIM "$N�Ե����̶��ֻ���,ʹ�������߹�����������\n" NOR;
			COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		}
	}
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(3);
	return 1;
}

