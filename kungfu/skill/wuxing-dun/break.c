// break.c ��ݾ�ɱ
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int count;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ݾ�ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query("qi") < 100 )
		return notify_fail("�����������\n");
	if( (int)me->query("max_neili") < 200 )
		return notify_fail("�������������\n");
	if( (int)me->query("neili") < (int)me->query("max_neili")/2)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 30)
		return notify_fail("���ɱ���ķ���򲻹���\n");

	if((int)me->query_skill("wuxing-dun",1) < 50)
		return notify_fail("������ж��е���Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("dodge") < 50)
		return notify_fail("����Ṧ��Ϊ������ Ŀǰ����ʹ��! \n");

	msg = HIC "$Nʹ�����ж��еġ���ݾ�ɱ��������Ȼ���ñ��Ī�⣡\n" NOR;
	message_vision(msg, me, target);
	count = (int)me->query_skill("wuxing-dun") / 40 + 2;
	if( count > 6 ) count = 6;
	while( count-- )
	{
		object ob;
		me->clean_up_enemy();
		ob = me->select_opponent();
		if( !ob || (environment(ob) != environment(me)) || !me->is_fighting(target) || !living(target) )
		{
			message_vision(WHT "$N������ٿ��һת������ͣס�˽Ų���\n" NOR, me);
			break;
		}
		else
     
			message_vision(WHT "$N����Ӱ��$n����ʱ��ʱ�� ...\n" NOR, me, target);
		COMBAT_D->do_attack(me, ob);
		//if (!me->query("double_attack"))
			//COMBAT_D->fight(me, ob);
		me->receive_damage("qi", 30);
		me->add("neili", -50);
	}
	me->start_busy(5);
	return 1;
}

