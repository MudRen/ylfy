// lian.c ����ָ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int skill,level;


	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("canhe-zhi",1) < 200 )
		return notify_fail("��Ĳκ�ָ��򲻵����޷�ʩչĽ�ݼҴ���ѧ��\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 180)
		return notify_fail("�����Ԫ�����̫ǳ��\n");

	if ((int)me->query_skill("canhe-zhi", 1) < 180)
		return notify_fail("��Ĳκ�ָ���̫ǳ��\n");
	if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
		return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");

	skill = me->query_skill("canhe-zhi", 1);

	if (me->query("neili") < 700)
		return notify_fail("��������������޷����á�����ָ����\n");

	if (me->query_skill_mapped("unarmed") != "canhe-zhi")
		return notify_fail("��û�м����κ�ָ, ����ʹ�á�����ָ����\n");

	msg = HIC "$N" HIC "��ָ���������һ��ʢ������������ƮƮ�ķ���$n" HIC "��\n" NOR;

	me->add("neili", -30);
	ap = me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
	dp = target->query_skill("dodge") + target->query_skill("parry") + me->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "���$p" HIR "��$P�Ƶ��мܲ�������Ͼ�Թˡ�\n" NOR;
		target->start_busy(random(4) + 2);
	}
	else
	{
		msg += CYN "����$p" CYN "������$P����ͼ������һԾ���㿪����һ�С�\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	msg = HIW "ֻ��$N" HIW "����һչ������Ȼ��ù����ޱȣ�������ָ��Ȼ��������ɽ���ֱϮ$n" HIW "ҪѨ��ȥ��\n" NOR;

	message_vision(msg, me, target);

	me->start_busy(3);
	me->add("neili", -300);
	level = me->query_skill("canhe-zhi", 1);
	me->add("apply/attack", level);
	msg = MAG "$Nһָ����$n������Ѩ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = YEL "$N��ָ����$n������Ѩ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = WHT "$N��ָ����$n�Ĵ��Ѩ"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =RED "$N��ָ����$n���Ϲ�Ѩ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIR "$N��ָ����$n����ԨѨ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIC "$N��ָ����$n���쾮Ѩ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIB "$N��ָ����$n�ļ�ȪѨ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = GRN "$N��ָ����$n������Ѩ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("apply/attack", -level);

	return 1;
}

