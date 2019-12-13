// po.c �������ơ�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	int skill, jing_cost;
//    mapping my_fam  = me->query("family");
	skill = me->query_skill("cuixin-zhang",1);
	if (me->query_int()<50)
		jing_cost = (int)me->query_int() - 50;
	else    jing_cost=1;
	if( me->is_fighting() )
		return notify_fail("�������ơ�������ս����������\n");

	if( me->query_temp("weapon"))
		return notify_fail("�㲻���ñ�����\n");
	if( !skill || (skill < 60))
		return notify_fail("��Ĵ����Ƶȼ�����, ���������������ơ���\n");
	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("������ʽ��ֻ�������ɴ��˲���ʹ�á�\n");

	if( me->query("neili") < 50 )
		return notify_fail("�������������û�����������������ơ���\n");
	if (me->query_skill("unarmed",1)<= skill)
		return notify_fail("��Ļ���ȭ�Ų������޷�ͨ�������������ơ���ߴ����Ƶļ��ɣ�\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о��������������ơ���\n");
	msg = HIC "$N��ϥ����������������һʽ�������ġ��ó�������Ӱ��\n" + NOR;
	message_vision(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60)
		me->improve_skill("cuixin-zhang", 10);
	else if (skill < 90)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() - 9));
	else if (skill < 140)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 2 - 9));
	else if (skill < 200)
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 4 - 9));
	else
		me->improve_skill("cuixin-zhang", 10 + random((int)me->query_int() * 8 - 9));
	msg = MAG"$N�Ĵ���������ǿ�ˡ�\n"NOR;
	if (random(10)>8)    me->start_busy(1);
	message_vision(msg, me);
	return 1;
}
