//��ţ��ʽ
// by mudwu
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
		return notify_fail("��"+HIY"��ţ��ʽ"NOR+"��ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_str() < 40)
		return notify_fail("��ı�������, ������ʹ���������! \n");
	if((int)me->query_skill("blade",1) < 250)
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if (me->query_skill_mapped("blade") != "jieniu-dao")
		return notify_fail("��û�м�����ţ�����޷�ʩչ����ţ��ʽ����\n");
	if((int)me->query_skill("jieniu-dao",1) < 250)
		return notify_fail("��ľ��а˷��Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("���������Ϊ������\n");
	msg =
	    HIW "\n$N��շ���,���б�����������Ĺ�â������һƬƬ��ʵ�ʰ㵶���ӿ����֡�\n" NOR;
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
	me->add("neili",-random(2500)-150);
	me->start_busy(3+random(1));
	return 1;
}
