// jianzhang.c  ����������
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
		return notify_fail("��������������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("����������������ʼʱ��������һ�ѽ���\n");
	if (me->query_temp("perform"))   return notify_fail("����һ����ʽ��û���!\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");
	if( (int)me->query_skill("sword") < 50 || me->query_skill_mapped("sword") != "huashan-jianfa")
		return notify_fail("��Ļ�ɽ�����������ң��޷�ʹ�ý�����������\n");
	msg = HIY "$Nʹ����ɽ�ɾ�������������������������Ȼ�ӿ죡\n" NOR;
	message_vision(msg, me);
	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add("neili", -100);
	me->set_temp("perform",1);
	call_out("del_perform",3,me);
	return 1;
}
void del_perform(object me)
{
	if (!me) return;
	me->delete_temp("perform");
}
