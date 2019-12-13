// jinglei.c ��ָ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("tanzhi-shentong",1);

	if( !(me->is_fighting() ))
		return notify_fail("����ָ���ס�ֻ����ս����ʹ�á�\n");

	if ( objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ����������\n");

	if( skill < 120)
		return notify_fail("��ĵ�ָ��ͨ�ȼ�����, ����ʹ�á���ָ���ס���\n");

	if( me->query("neili") < 150 )
		return notify_fail("��������������޷����á���ָ���ס���\n");

	msg = HIC "$Nʹ����ָ��֮ͨ����ָ���ס�, ��ʱ���ھ��Ⱪ�䣬\n";
	message_vision(msg, me, target);

	dp = target->query("xyzx_sys/level");

	if( random(me->query("xyzx_sys/level")) > random(dp))
	{
		if(userp(me))
			me->add("neili",-150);
		msg = "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n" ;
		if ( objectp(weapon2 = target->query_temp("weapon")))
		{
			msg += "ͬʱ����һ�飬����";
			msg += weapon2->name();
			msg += "���ֶ�����\n" NOR;
			weapon2->move(environment(me));
		}
		wound = skill + random(skill);
		if((int)target->query("neili") < wound)
			wound = target->query("neili") +10;
		target->add("neili", -wound);
		target->receive_wound("jing", wound/5, me);
		target->start_busy(5);
		me->start_busy(2);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�\n"NOR;
		me->start_busy(3);
		message_vision(msg, me, target);
	}

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
