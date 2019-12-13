// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������ơ�ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("��Ŀ�����Ӱ��������죬�����ÿ������ơ�\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("��Ŀ����ķ�������죬����ʹ�ÿ������ơ�\n");

	extra = me->query_skill("kuihua-feiying",1) / 15;
	extra += me->query_skill("kuihua-xinfa",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N����ۿ����ķ��ݣ�ͬʱʹ���ۿ������ƣ������Ĵ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "$N����Ӱ����˼�������������\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = HIC "��$n�����Գ���һ����Ӱ��һ����$n���˹�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
