// maze.c ���Ű�������

#include <ansi.h>
inherit F_SSERVER;
int exert(object me)
{
	string msg;
	object target;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������תֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("neili") < 800  )
		return notify_fail("�������������\n");
	if( (int)me->query_skill("qimen-wuxing",1) < 1000  )
		return notify_fail("����������в�����\n");
	if( (int)me->query_skill("count",1) < 1000  )
		return notify_fail("����������Բ�����\n");
	if( (int)me->query_temp("thd/maze") > 2 )
		return notify_fail("�������ֻ�ܲ���������\n");

	if( me->query_skill("bibo-shengong", 1) < 900 )
		return notify_fail("����ڹ���Ϊ���δ������δ���������󷨡���\n");
	if (!userp(target))
		return notify_fail("ֻ�ܶ����ʹ��!\n");
	skill = me->query_skill("qimen-wuxing", 1);
	me->add("neili", -580);
	msg = HIG "$N����������ʢ�����»������žŹ����Է�λ��ͷ��ð�����ڰ�����";
	msg += "��������������ӿ֮�����̲����ѷ��ӵ����£�\n"NOR;

	message_vision( HIC "$Nһ����ս��һ��������Χ��ʯ�顢��֦�Ȳ���һ���򵥵���\n" NOR, me);
	if (random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/4)
	{
		message_vision(
		    HIC "$N����һ�ԣ�ֻ������һ�㣬��֪�ߵ�����ȥ��!\n" NOR, target);
		if (random(12)==0)
			target->move("/d/sdxl/linhai5");
		else if (random(12)==1)
			target->move("/d/jqg/hc4");
		else if (random(12)==2)
			target->move("/d/taohua/tao0");
		else if (random(12)==3)
			target->move("/d/feitian/senlin1");
		else if (random(12)==4)
			target->move("/d/feitian/shulin2");
		else if (random(12)==5)
			target->move("/d/shaolin/bamboo3");
		else if (random(12)==6)
			target->move("/d/shaolin/bagua3");
		else if (random(12)==7)
			target->move("/d/xingxiu/silk2");
		else if (random(12)==8)
			target->move("/d/xingxiu/shamo4");
		else if (random(12)==9)
			target->move("/d/gaochang/room40");
		else if (random(12)==10)
			target->move("/d/gumu/shulin4");
		else if (random(12)==11)
			target->move("/d/meizhuang/senlin7");
		else
			target->move("/d/taohua/tao0");
		me->add_temp("thd/maze", 1);
		message_vision(msg, me);
	}
	else
		message_vision(
		    HIC "$N���һ����֪������������ԶԶ����������\n" NOR, me);
	target->start_busy(6);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

