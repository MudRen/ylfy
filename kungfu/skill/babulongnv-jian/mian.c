// mian.c �˲���Ů�������ལ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ལ�� ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if( (int)me->query_skill("babulongnv-jian", 1) < 100 )
		return notify_fail("��İ˲���Ů����������죬����ʹ�á����ལ�� ����\n");
	i = me->query_skill("babulongnv-jian",1);
	msg = HIM "$N���⶷�������������˿һ��Ľ��������಻������$n���ƹ�ȥ��\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/5 || random(me->query("sword")) > target->query("dodge")/3 )
	{
		msg += HIC " ���$p��$P�����˿�㽣�����������У��������á�\n" NOR;
		
		if(i > 20)i = 20;

		target->start_busy(i);
		target->apply_condition("no_perform", i);
		me->add("neili", -200);
	}
	else
	{
		msg += "����$p������$P����ͼ�����Ծ�������ȥ��\n" NOR;
		me->start_busy(2);
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

