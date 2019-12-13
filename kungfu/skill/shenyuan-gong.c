//��Ԫ��

inherit FORCE;

int valid_enable(string usage)
{
	return usage=="force";
}

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i, nh;
	nh = (int)me->query_skill("shenyuan-gong", 1);
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷������Ԫ����\n");
    if ( me->query("gender") == "����" && nh > 49)
        return notify_fail("���޸����ԣ������������������������Ԫ����\n");
	 if (me->query_skill("force",1)<=nh)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="shenyuan-gong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ������\n");
	}

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��Ԫ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shenyuan-gong/" + func;
}

