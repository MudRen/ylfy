#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("wenrou-jian",1);
	if ( extra < 120) 
		return notify_fail("������ϸ�����ὣ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(""HIR"��"HIW"��Ц��ԯ"HIR"��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	message_vision(HIW"$N���е�"NOR+ weapon->name()+ HIW "һ���ʣ��ͻ���һ���⻪����$n"HIW"��һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$n"HIG"ֻ��������⻪�ݷ�����Լ�ü��
	               �䣬ȴ�ֲ���ȷ������������ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(HIY"������ȷʵ����������޴����ڡ����Ǿ���$n"HIY"��ȷ��������ʱ������Ȼ�ֲ����ˡ�"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(HIR"���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ�����������ǣ�ȴ���������磬ȴ�ֱ����Ǻ�������ӽ��漣����Ϊ�߶���仯������������$N�������ġ�"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->start_busy(1+random(2));
	me->start_busy(1+random(2));
	return 1;
}
