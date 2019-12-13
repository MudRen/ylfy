#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ջ��ǳ���ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_skill("sword",1) < 500)
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("guxing-sword",1) < 500)
		return notify_fail("��Ĺ��ǽ����Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("���������Ϊ������\n");
	msg = YEL "\n$N����һ��üͷ���������ݵ�ʹ�����ǽ����е����ɱ�С��ջ��ǳ�����\n" NOR;
	message_vision(msg, me);
	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add("neili",-5000);
	me->start_busy(random(3));
	return 1;
}
