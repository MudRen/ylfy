// ��������
// bye jfeng
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
		return notify_fail("���������졹ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_str() < 40)
		return notify_fail("��ı�������, ������ʹ���������! \n");
	if((int)me->query_skill("axe",1) < 250)
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("leiting-axe",1) < 250)
		return notify_fail("������������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("���������Ϊ������\n");
	msg =
	    HIY "\n$N�������˿���������ΡȻ׿��������һ��ʹ�����������ľ������������졹��\n" NOR;
	message_vision(msg, me);
	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add("neili",-random(4500)-150);
	me->start_busy(1);
	return 1;
}
