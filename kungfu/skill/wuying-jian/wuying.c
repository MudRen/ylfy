//��ȥ������ wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon,ob;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������Ӱ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��������Ӱ�������ý�����ʩչ��\n");

	if( (int)me->query_skill("wuying-jian", 1) < 150 )
		return notify_fail("��ġ�������Ӱ����������죬����ʹ�á�������Ӱ����\n");

	if( (int)me->query("neili") < 300  )
		return notify_fail("�������������\n");

	skill = me->query_skill("wuying-jian");
	msg = HIG "$N����ͻ�䣬˲������ֳ�������Ӱ��������$n��ȥ��\n"NOR;
	message_vision(msg, me, target);

	me->add("neili", -200);

	me->clean_up_enemy();
	ob = me->select_opponent();
	msg = HIR"���־���\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIY"ȥ�־���\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
	msg = HIG"���־���\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIB"���־���\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIW"���־���\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}
