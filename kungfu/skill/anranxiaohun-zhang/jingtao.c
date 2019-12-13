// Code by JHSH

#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	int ap,dp;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ŭ�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֲ���ʩչ��ŭ�����Ρ���\n");

	if(me->query_skill_mapped("force") != "yunv-xinfa" )
		return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�\n");

	if( me->query_skill("anranxiaohun-zhang",1) < 550 )
		return notify_fail("����Ȼ��������Ϊ̫��������á�ŭ�����Ρ���\n");

	if ( !living(target))
		return notify_fail("���ڲ�û��Ҫ�á�ŭ�����Ρ��ɣ�\n");

	if( me->query("neili") <= 1000 )
		return notify_fail("�����������ʹ�á�ŭ�����Ρ���\n");

	ap = me->query_skill("force") + me->query_skill("unarmed");
	dp = target->query_skill("force") + target->query_skill("parry");
	damage = me->query_skill("unarmed") + me->query_skill("force") * random(me->query("con"));

	message_vision(HIW"\n$N���Ʒ��������ų�ӿ֮�����Ʒ�ĵ��������п�ӿ���������������������ں��������ľ����� \n\n"NOR,me,target);

	if (ap/2 + random(ap) > dp)
	{
		target->receive_damage("qi",damage);
		target->receive_wound("qi",random(damage)+200);
		message_vision(HIR"$n�����ܵÿ��������Ѿ���$N���Ʒ�ӡ���ؿڣ�һ����Ѫ���������\n\n",me,target);
		
		if (! target->is_busy())
			target->start_busy(3);
	}
	else
	{
		message_vision(HIY"$n��״������̾͵�һ���������Ȼ�����ѿ��Լ�����������ܿ���$N��һ�ơ�\n\n"NOR,me,target);
	}

	message_vision(HIW"\n$N���Ʒ�ﵽ����֮ʱ�����š��겻���ᡱ����������ʩ������������ʧ�����������С�\n\n"NOR,me,target);

	if (ap/2 + random(ap/2) > dp)
	{
		target->receive_damage("qi",damage*2);
		target->receive_wound("qi",random(damage*2)+200);
		message_vision(HIR"$n����δ����������֮�ʣ��������һ�����ҵ������������������$N�Ʒ��ش���\n\n",me,target);
		if (! target->is_busy())
			target->start_busy(3);
	}
	else
	{
		message_vision(HIY"$n�˲��÷���������������ɣ����ո�$N���Ʒ�ɨ����΢΢���죬��������ܿ���$N�����ơ�\n\n"NOR,me,target);
	}

	message_vision(HIW"����$N�������һ�С���ʬ���⡱��������߳�һ�š�\n\n"NOR,me);

	if (ap/3 + random(ap/3) > dp)
	{
		target->receive_damage("qi",damage*4);
		target->receive_wound("qi",random(damage*2)+200);
		message_vision(HIR"$n�ۿ�������������һ�ţ���Ȼ�����˵ֿ�������������$N�������ϣ����ݽ��飬��ĿѪɫ������\n\n",me,target);
		if (! target->is_busy())
			target->start_busy(3);
	}
	else
	{
		message_vision(HIY"$n˫���أ�������𣬴�$N��ͷ���ӹ������¾�����Х������������֮���գ�\n\n"NOR,me,target);
	}

	me->add("neili",-ap/2);
	me->start_busy(3);

	return 1;
}
