// qufeng.c ����֮��
// By Lgg,1998.9

inherit SKILL;

void create()
{
	seteuid(getuid());
}

string type()
{
	return "knowledge";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinjing", 1) < 100)
		return notify_fail("�����Ů�ķ���򲻹����޷�ѧ����֮����\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷�ѧϰ����֮����\n");
	if (((int)me->query_skill("qufeng",1)/10)*(int)me->query_skill("qufeng",1)*(int)me->query_skill("qufeng",1) >= (int)me->query("combat_exp",1))
		return notify_fail("���ʵս���鲻�㣬�޷�ѧϰ����֮����\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("����֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
