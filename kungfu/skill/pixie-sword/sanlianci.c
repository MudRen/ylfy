// jianzhang.c  ������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
 
	if( !target ) target = offensive_target(me);
	 if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������̡�ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������̡���ʼʱ��������һ�ѽ���\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if((int) me->query_skill("pixie-jian",1) < 100)
		return notify_fail("��ı�а�����������ң��޷�ʹ�������̣�\n");
	if ( (string)me->query("gender") != "����" )
		return notify_fail("�������֮�����㣬�޷�ʹ����а������\n");

	msg = RED "$N��ȻһЦ������֮��������Ȼ�ӿ죡" NOR;
	message_vision(msg, me);
msg = 	RED"�ȴ�˫Ŀ��"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"���˫�㣡"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"�����ģ�"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("neili", -50);
	me->start_busy(2);

	return 1;
}