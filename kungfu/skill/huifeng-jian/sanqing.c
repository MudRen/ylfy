// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��һ�������塹ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��һ�������塹��ʼʱ��������һ�ѽ���\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("huifeng-jian",1) < 100 )
		return notify_fail("��Ļط�������������ң��޷�ʹ�á�һ�������塹��\n");

	extra = me->query_skill("huifeng-jian",1) / 5;
	extra += me->query_skill("huifeng-jian",1) /5;

	msg = YEL "$Nʹ���ط������������һ�������塹��һ���������������е�"+ weapon->name()+  "����㹥����һ����" NOR;
	message_vision(msg, me);

	me->add_temp("apply/attack", extra*4);

	msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
	{
		msg = HIW "��һ������"+HIR+"����$n����$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;
		message_vision(msg, me, target);
		target->start_busy(2);
	}
	msg =  HIW "$N���һ����"+ weapon->name()+ GRN"����$n���Ҽ磡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query("xyzx_sys/level")> target->query("xyzx_sys/level")/3 )
	{
		msg = HIC "�ڶ�������"+HIM+"ɨ��$n������,$nֻ����ȫ��һ��ʹ��\n"NOR;
		target->add("jing",-extra*2);
		target->add("eff_jing",-extra*2);
		message_vision(msg, me, target );
	}
	msg = CYN "$N��Хһ�����۹��������֣�ʹ����������߾���--�𽣣���$n����ǰ��ȥ��" NOR;
	if (random(me->query_skill("force")) > target->query_skill("force") / 3)
	{
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = MAG "���һ������"+HIB+"ɨ��$n������Ѩ,$nֻ����ȫ�������᲻�����ˣ�\n"NOR;
		target->add("neili",-extra*4);
		target->add("eff_neili",-extra*4);
		message_vision(msg, me, target );
	}
	me->add("neili", -300);
	me->add_temp("apply/attack", - extra*4);
	me->start_busy(3);

	return 1;
}

