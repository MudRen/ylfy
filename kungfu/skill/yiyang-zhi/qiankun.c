// qiankun.c һ��ָ ��һָǬ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("��һָǬ����ֻ����ս����ʹ�á�\n");

	if((int)me->query_str() < 28)
		return notify_fail("���������,����ʹ����һ����!\n");
	
    if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ��һָǬ������\n");
	
	if((int)me->query_skill("kumu-shengong",1) < 90)
		return notify_fail("����������Ĺ�����������ʹ��һָǬ��!\n");

	if((int)me->query_skill("sun-finger",1) < 90)
		return notify_fail("���һ��ָ��Ϊ����,Ŀǰ������ʹ��һָǬ������!\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("��������Ϊ����, ����ʹ��һָǬ��! \n");

	if((int)me->query("neili") < 200)
		return notify_fail("���������ڲ���, ����ʹ��һָǬ��! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = CYN "$Nʹ��һ��ָ������һָǬ��������ס$n��ȫ��ҪѨ, ��ͼʹ$n�������á�\n"NOR;

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg +=   "���$n��$N���˸����ֲ���! һʱ���ܶ���! \n";
		target->start_busy( (int)me->query_skill("yiyang-zhi",1) / 100 + 4);
		me->add("neili", -200);
	}
	else
	{
		msg += "����$n������$N����ͼ����û���ϵ���\n";
		me->start_busy(3);
		me->add("neili", -200);

	}
	message_vision(msg, me, target);

	return 1;
}
