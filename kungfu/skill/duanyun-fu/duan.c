//duan.c -��������֮������ն��
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ն����\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query_skill("duanyun-fu",1) < 70)
		return notify_fail("��Ŀǰ������ʹ����������ն����\n");
	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");
	me->add("neili", -60);
	msg = HIC"$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
	return 1;
}

