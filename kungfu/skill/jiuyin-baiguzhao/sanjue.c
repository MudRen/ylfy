// sanjue ��������צ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int str, dex, skill, i, damage;
	string msg;
	str = (int)me->query("str");
	dex = (int)me->query("dex");
	skill = (int)me->query_skill("jiuyin-baiguzhao", 1);
	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) )
		return notify_fail("����������צ��ֻ����ս����ʹ�á�\n");
	if( me->query_temp("weapon"))
		return notify_fail("������������ô��ʹ�á���������צ����\n");
	if(me->query_skill("jiuyin-zhenjing",1) < 1000 )
		return notify_fail("��ľ����澭��������죬ʹ��������������צ��������\n");
	if( skill < 3000 )
		return notify_fail("��ľ����׹�צ��������죬ʹ��������������צ��������\n");

	if ( me->query_skill_mapped("unarmed") != "jiuyin-baiguzhao" )
		return notify_fail("�������޷�ʹ�á���������צ����\n");
	if( (int)me->query("max_neili") < 80000 )
		return notify_fail("����������̫����ʹ��������������צ����\n");
	if( (int)me->query("neili") < 8000 )
		return notify_fail("����������̫����ʹ��������������צ����\n");

	me->start_perform(2, "��������צ");
	message_vision(HIR"\n$N�ֱ�ͻȻ�쳤����$nץȥ��\n"NOR,me,target);
	message_vision(RED"\n$N��ʹ���ƺ��ǽ����г�����������������׹�צ����������������������ǿ����\n"NOR,me,target);
	if (!target->is_busy()) target->start_busy(5);
	me->add("neili", -1000);
	me->add_temp("apply/strength",str/2);
	me->add_temp("apply/dexerity",dex/2);
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage", skill/2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/damage", -skill/2);
	me->add_temp("apply/attack", -skill/2);
	me->add_temp("apply/strength",-str/2);
	me->add_temp("apply/dexerity",-dex/2);

	msg = HIB "\n$Nһ����Х������$n��ת��Ȧ������ʩչ�����ݽ��ƹǡ���˫צ�����ֱ��$nǰ�ء�\n"NOR;
	if (userp(target))
	{
		if ( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/4 )
		{
			msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
			damage = skill * 50 + random(skill);
			target->add("jing",-damage);
			target->add("eff_jing",-damage/2);
			msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
			me->add("neili", - 600);
		}
		else
		{
			msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض��롣\n" NOR;
		}
		message_vision(msg, me, target );
		me->start_busy(2 + random(i));
		if (!target->is_busy()) me->start_busy(5);
	}
	else
	{
		if (random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
		{
			msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
			damage = skill * 50 + random(skill);
			target->add("jing",-damage);
			target->add("eff_jing",-damage/2);
			msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
			me->add("neili", - 600);
		}
		else
		{
			msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض��롣\n" NOR;
		}
		message_vision(msg, me, target );
		me->start_busy(2 + random(i));
		if (!target->query_condition("no_perform") )
		{
			target->apply_condition("no_perform", 10);
			message_vision( HIC"\n$n��$N����Ѩ��������������������תʧ�飬����ʩչ�⹦��\n" NOR, me, target);
		}
		if (!target->is_busy()) me->start_busy(4);
	}
	return 1;
}
