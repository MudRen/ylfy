// tiaoyan.c ��������֮������ʽ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	damage = (int)me->query_skill("duanyun-fu",1);
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ʽ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "����ֻ��ͷ��Ӭ����ŵ������ɡ�\n");
	msg = HIG "$Nʹ����������֮������ʽ�������⼲��$n˫�ۡ�\n";

	me->start_busy(random(3));
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += "���$pֻ������ǰһ�ڣ�˫��һ���ʹ������ʲôҲ�������ˡ�\n" NOR;
		target->start_busy( (int)me->query_skill("duanyun-fu") / 50 + 2);
		target->receive_damage("qi",damage,me);
	}
	else
	{
		msg += "����$p������$P����ͼ������æ�㿪�ˡ�\n" NOR;
		me->start_busy(random(2));
	}
	message_vision(msg,me,target );

	return 1;
}

