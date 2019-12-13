// pili-dan.c ������
inherit SKILL;

int valid_enable(string usage)
{
	return usage=="throwing" ;
}
int valid_learn(object me)
{
	if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
		return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ��������\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����������\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
		return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������������\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"pili-dan/" + action;
}
