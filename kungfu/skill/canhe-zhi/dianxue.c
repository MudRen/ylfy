// fuxue.c �黨ָ ���黨��Ѩ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���黨��Ѩ��ֻ����ս����ʹ�á�\n");

	if((int)me->query("str") < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("canhe-zhi",1) < 150)
		return notify_fail("��κ�ָ�Ĺ�����������ʹ���黨��Ѩ!\n");

	if((int)me->query_skill("unarmed",1) < 100)
		return notify_fail("���ȭ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!\n");

    if((int)me->query("neili") < 300)	
        return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! \n");	

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIG "$Nʹ���κ�ָ�������黨��Ѩ����һָ��$n��ȫ��ҪѨ��ȥ, ʹ$n�������á�\n";

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/5 || random(me->query("unarmed")) > target->query("dodge")/10 )
	{
		msg +=  HIG "���$p��$P�����˼���Ѩλ! \n" NOR;
		target->start_busy( (int)me->query_skill("canhe-zhi",1) / 50 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
message_vision(msg, me, target);	

	return 1;
}
