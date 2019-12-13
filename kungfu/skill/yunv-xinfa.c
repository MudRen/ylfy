// yunv-xinfa.c ��Ů�ķ�

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ������ѵ���������ϰ��Ů�ķ���\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="yunv-xinfa") continue;
		if (sname[i]=="yunv-xinjing") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ľ�����\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��Ů�ķ�ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}

