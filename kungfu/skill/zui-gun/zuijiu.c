// zuijiu.c �������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i, attack_time;
	string msg;
	int extra;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) || !living(target))
		return notify_fail("���������ֻ����ս���жԶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club" || me->query_skill_mapped("club") != "zui-gun")
		return notify_fail("�������޷�ʹ�á�������򡹡�\n");

	if( (int)me->query_skill("zui-gun",1) < 500 )
		return notify_fail("������������죬����ʹ�á�������򡹣�\n");

	if( (int)me->query("str") < 30 )
		return notify_fail("��ı�������ǿ������ʹ�á�������򡹣�\n");

	if( (int)me->query("max_neili") < 200000 )
		return notify_fail("�������̫��������ʹ�á�������򡹣�\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó���������򡹣�\n");
	
	extra = (int)me->query_condition("drunk");
	attack_time = (int)me->query_skill("zui-gun", 1) /100;

	message_vision(HIY"\n$NͻȻһ�����ã���ʱ���žƾ��ʹ��������������\n"NOR,me);
	if (random(2)==0) target->apply_condition("no_perform", 3);
	if (attack_time > 50) attack_time = 50;
	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
    me->add_temp("lianzhao",attack_time);
	for(i=0; i < attack_time; i++)
	{
		if(!me->is_killing(target) && !target->is_killing(me) && !target->is_fighting(me))
			break;
		//msg = HIR  "$NͻȻһ�����ã���֪�Ӻδ������"+(i+1)+"����\n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->add("jing", 20);
	me->start_busy(3);
	return 1;
}
