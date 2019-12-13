// biyun-xinfa.c �����ķ�
// cleansword

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
	int lvl = (int)me->query_skill("biyun-xinfa", 1);

	if ( (me->query("family/family_name") != "����"))
		return notify_fail("�����ķ������Ŷ�����, �����ŵ��Ӳ���!\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���Ų�Ҫ�������޸����Ե��ˣ����޷�������ı����ķ���\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������ķ���\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="biyun-xinfa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����\n");
	}
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"biyun-xinfa/" + func;
}
