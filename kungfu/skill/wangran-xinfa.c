// wangran=xinfa.c ��Ȼ�ķ�
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
	int lvl = (int)me->query_skill("wangran-xinfa", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ������������������������Ȼ�ķ���\n");
	if ((int)me->query_skill("force", 1) < 10)
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
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="wangran-xinfa") continue;
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ڤ�񹦣���\n");
	}
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("��Ȼ�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"wangran-xinfa/" + func;
}
