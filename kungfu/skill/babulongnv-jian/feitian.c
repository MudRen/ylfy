// feitian.c ���ܾ�ʽ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;

	skill = me->query_skill("babulongnv-jian",1);
	jing_cost = (int)me->query("int") - 45;

	if( me->is_fighting() )
		return notify_fail("���˲����졹������ս����������\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������ȥ��һ�ѽ���\n");

	if( me->query("neili") < 150 )
		return notify_fail("�������������û�������������˲����졹��\n");

	if( me->query("jing") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о����������˲����졹��\n");

	msg = HIC "$Nʹ���˲���Ů��֮���˲����졹������" + weapon->name() + ""HIC"Χ���Լ���ͣ�ƶ���\n";
	message_vision(msg, me);

	me->add("neili", -50);
	me->add("jing", jing_cost);

	if ( skill < 60)
		me->improve_skill("babulongnv-jian", 10);
	else if (skill < 90)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") - 8));
	else if (skill < 140)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 2 - 8));
	else if (skill < 200)
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 4 - 8));
	else
		me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

	msg = MAG"$P�ġ��˲���Ů�����������ˣ�\n"NOR;
	me->start_busy(random(3));

	message_vision(msg, me);

	return 1;
}

