#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����Ļ�ϡ�ֻ����ս����ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����Ļ�ϡ�ֻ�ܿ���ʹ�á�\n");

	if( me->query_skill_mapped("unarmed") != "qishang-quan" )
		return notify_fail("��û��ʹ������ȭ����\n");

	if( (int)me->query("neili") < 700 )
		return notify_fail("�������������\n");

	if( me->query_skill("qishang-quan",1) < 150 )
		return notify_fail("�������ȭ��򲻹����޷�ʹ�á����Ļ�ϡ���\n");

	if( (int)me->query_skill("force",1) < 110 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����Ļ�ϡ���\n");

	weapon = me->query_temp("weapon");

	msg = HIW "$N���λ�ת��ŭ��һ����ͬʱʹ������ȭ�еľ��裬һ��[���Ļ��]��������$n��" NOR;
	message_vision(msg, me, target);
	msg =  HIW  "�������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "�ݳ�����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "��ʧ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "��������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "�˷ξ���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "���ľ���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "���㱾���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -700);
	me->start_busy(5);

	return 1;
}

