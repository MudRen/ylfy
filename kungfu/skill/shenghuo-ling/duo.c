// duo.c ʥ��������桹��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon,weapon2;
	string msg;
	int    iDuo;

	weapon2 = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ʥ��������桹��ֻ����ս����ʩ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("�Է�����û����������ʹ�����С���������Ծ����ɵ�ϡ�\n");


	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if( (int)me->query_skill("shenghuo-ling", 1) < 50 )
		return notify_fail("���ʥ���������죬ʹ���������桹�\n");

	msg = HIY"$Nʹ��ʥ��������桹������������Ȱ����ʽ��$n��������ơ�\n"NOR;

	me->start_busy(1);

	if( (string)weapon2->query("id") == "shenghuo-ling" )
		iDuo = 4 ;
	else
		iDuo =3 ;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/iDuo )
	{

		msg += HIR"$n��ʱ����˫���������飬��Ȼ����һ�飬����";
		msg += weapon->name();
		msg += "��Ȼ���׶��ɣ�\n";
		msg += "ϸ��ʱ���ѱ�$N�������˻��У�\n"NOR;

		target->start_busy(2);
		weapon->move(environment(me));
//		weapon->move(me);
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}


	message_vision(msg, me, target);

	return 1;
}
