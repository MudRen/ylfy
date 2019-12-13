// shenlong-xinfa.c �����ķ�

inherit FORCE;
int valid_enable(string usage)
{
	return usage=="force";
}
int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("shenlong-xomfa", 1);
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������������ķ���\n");
	if (me->query_skill("force",1)<20)
		return notify_fail("��Ļ����ڹ���������������ѧ�����ķ���\n");
	if (me->query_skill("force",1)<=lvl)
		return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="shenlong-xinfa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shenlong-xinfa/" + func;
}
