// ��������ɽ rao.c
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character()|| !me->is_fighting(target) )
		return notify_fail("��������ɽֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");

	if(me->query("family/family_name") != "�����" && me->query("combat_exp") > 50000000)
	{
		msg = HIW "$N��ħ������������λ�߻���ħ��\n";
		message_vision(msg, me, target);
		/*
		        me->delete_skill("dieyi-jianfa");
		        me->delete_skill("wudie-xinjing");
		        me->delete_skill("wudie-bu");
		*/
		me->add("neili", -5000);
		// me->set("qi",0);
		return 1;
	}

	if( (int)me->query_skill("dieyi-jianfa", 1) < 50 )
		return notify_fail("��ĵ�������������죬����ʹ�á������־���\n");

	msg = HIW "$Nʹ��������֮��������ɽ����$n����������ؽ�Ӱ��\n";
	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/10 )
	{
		msg += RED " ���$n��$N���˸����ֲ�����\n" NOR;
		target->start_busy( 10+random(4) );
	}
	else
	{
		msg += MAG "����$n������$N����ͼ����û���ϵ���\n" NOR;
		me->start_busy( 1+random(1) );
	}
	message_vision(msg, me, target);

	return 1;
}

