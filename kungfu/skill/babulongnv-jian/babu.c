#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)

{
	object weapon;
	string msg;
	int damage;
	weapon = me->query_temp("weapon");
	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("���˲�����ֻ����ս����ʹ�á�\n");
	if( (int)me->query_str() < 40 || (int)me->query_dex() < 40 || (int)me->query_con() < 40 || (int)me->query_int() < 50 )
		return notify_fail("�����ڻ��ò�����ô�������ľ���.\n");
	
	if (me->query_skill_mapped("parry") != "babulongnv-jian")
		return notify_fail("����ʹ�õ��мܲ��ԡ�\n");
	
	if( (int)me->query("max_neili") < 1200 )
		return notify_fail("��ôǿ���似������������������Ϊ�����õģ�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");
	msg = HIC "\n$N����һ��"HIY"���˲�������˻ꡱ"BLU"����Ů���쾪��ħ!��"HIC"����һԾ���ټ�ȫ�ޣ���\n" NOR;
	if (random(me->query("per")) > target->query("per") / 3)
	{
		msg += HIR "��Ȼ�䣬$N������£�ǧ˿��������$n�����������ޱȣ�ֱ����Ůɢ����$n���ô��ˣ���Ȼ�����˳���\n"NOR;
		target->start_busy(7);
		damage = me->query_skill("babulongnv-jian") * me->query("per");
		damage = damage + random(damage/2);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		me->add("neili", -200);
		call_out("perform2", 6, me, target);
	}
	else
	{
		me->start_busy(1);
		me->add("neili", -100);
		msg += HIW"$nȫ���ע���������⣬$N�ۼ��޻��ɳã�ֻ�ý�������¶������\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

int perform2(object me, object target)
{
	string msg,msg1;
	int i;
	object weapon;
	weapon = me->query_temp("weapon");

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("���˲�����ֻ����ս����ʹ�á�\n");

	if (!me || !target) return 0;
	if(!living(target))
		return notify_fail("�����Ѿ�������ս���ˡ�\n");
	if (!weapon || weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "babulongnv-jian")
		return notify_fail("�������޽����˲������޷�ʹ�꣡\n");
	if( (int)me->query("neili", 1) < 800 )
		return notify_fail("���Ҫ�ٳ�ʤ׷����ͻȻ�����Լ��Ѿ����������ˡ�\n");

	i = (me->query_skill("sword")*2/3);
	msg = HIW "$N���е�"+weapon->query("name")+HIW"��ͬ����һ��Χס�Լ�ת����Ϣ������һ������֮����Ѹ���ޱȵ�����$n��\n"NOR;
	msg1=YEL"$N��ص��棬����$n����֮ʱ�����ӹ�����\n"NOR;
	me->add_temp("apply/attack", i);
	me->add_temp("apply/dodge", i);
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK);
	msg = HIR "$N���������������ƻ�,���в���$n��Ҫ��֮����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK);
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK);
	msg = HIC "$N����ش�,��Ȼ��$n����������ƻ�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(target,target, me->query_temp("weapon"),TYPE_QUICK);
	message_vision(msg, me, target);
	COMBAT_D->do_attack(target,target, me->query_temp("weapon"),TYPE_QUICK);
	me->add("neili", -300);
	target->start_busy(2);
	me->add_temp("apply/attack", -i);
	me->add_temp("apply/dodge", -i);
	message_vision(msg1, me,target);
	call_out("perform3", 2, me, target);
	return 1;
}


int perform3(object me, object target)
{
	object weapon;
	string msg;
	int skill, damage, p;
	weapon = me->query_temp("weapon");
	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("���˲�����ֻ����ս����ʹ�á�\n");

	skill = (int)me->query_skill("babulongnv-jian", 1);

	if(!living(target))
		return notify_fail("�����Ѿ�������ս���ˡ�\n");

	if( (int)me->query("neili", 1) < 800 )
		return notify_fail("���Ҫ�ٳ�ʤ׷����ͻȻ�����Լ��Ѿ�����������!\n");

	msg = HIG "\n$N���е�"+weapon->query("name")+HIG"������Բ����Ļ��$Nȫ��ס��Ȼ��Ϊһ���޴�Ĺ�������һ������$n��\n"NOR;
	if (random(20) > 10)
	{
		msg += HIR "$n����������δ�����㣬��$N�ľ޴����͸����������\n" NOR;
		me->start_busy(2);
		target->start_busy(2);
		damage = skill*8;
		damage = damage + random(damage/8);
		p = target->query("qi")*100/target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";

		target->receive_damage("qi", damage*2/5);
		target->receive_wound("qi", damage*2/5);
		me->add("neili",700);
	}
	else
	{
		me->add("neili", -200);
		target->start_busy(3);
		msg += HIW"\n$n��æһ����ͷ����Ȧ�⣬ȴҲ���ŵĻ����Ǻ���\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

