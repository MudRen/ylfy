// wuji-shengong.c �޼���

inherit FORCE;
inherit F_DBASE;
public string query_type()
{
	return "yin";
}

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
// need more limit here
{
	mapping skl;
	string *sname;
	int i;
	int lvl= (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < lvl / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if ( me->query("gender") == "����" && me->query_skill("wuji-shengong",1) > 49)
		return notify_fail("���޸����ԣ�����������������������޼��񹦡�\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="wuji-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�޼��񹦣���\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�޼���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"wuji-shengong/" + func;
}
