//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	int extra;
	object weapon;
	extra = me->query_skill("murong-jianfa",1);
	if ( me->query_skill("murong-jianfa",1) < 200) 
		return notify_fail("���Ľ�ݽ������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�ۿ콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!weapon || weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "murong-jianfa")
		return notify_fail("������û�н����޷�ʹ�ãۿ콣��\n");
	if ((int)me->query("neili")<150)
		return notify_fail("�������������\n");
	me->add("neili",-150);
	weapon = me->query_temp("weapon");
	message_vision(HIM"$Nʹ��Ľ�ݽ����еľ��Уۿ콣�ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);
	if (random((int)me->query_skill("dodge"))>random((int)target->query_skill("dodge")/3 ) )
	{
		COMBAT_D->do_attack(me,target, weapon);
		message_vision(HIW"��ɽ������\n" NOR,me,target);
		COMBAT_D->do_attack(me,target, weapon);
		message_vision(HIC"̩ɽ������\n" NOR,me,target);
		COMBAT_D->do_attack(me,target, weapon);
		message_vision(HIR"��ɽ���񽣣�\n" NOR,me,target);
		COMBAT_D->do_attack(me,target, weapon);
		message_vision(HIY"��ɽ������\n" NOR,me,target);
		COMBAT_D->do_attack(me,target, weapon);
		message_vision(HIB"��ɽ������\n" NOR,me,target);
		COMBAT_D->do_attack(me,target, weapon);


		message_vision(WHT"$N�������������$n�����˸���æ���ң�\n" NOR,me,target);
		me->start_busy(2);
		target->start_busy(3);
	}
	else
	{
		message_vision(HIC"����$n������$N����ʽ,�û�����������\n" NOR,me,target);
		me->start_busy(3);
	}
	return 1;
}