// wudie-xinjing.c ����ľ�
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("wangran-xinfa", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	if ( me->query("gender") == "����")
		return notify_fail("���ֲ���Ů�ˣ����������������ľ���\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ��������������������������ľ���\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("�����������̫���ˡ�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("�����������̫���ˡ�\n");
	}
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("����ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"wudie-xinjing/" + func;
}

