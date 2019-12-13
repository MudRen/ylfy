// shenghuo-shengong.c ʥ����

inherit FORCE;

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
	int lvl = (int)me->query_skill("shenghuo-shengong", 1);
	int t = 1, j;

	if(lvl <= 100)
		for (j = 1; j < lvl / 10; j++)
			t *= 2;


	if ( me->query("gender") == "����" )
		return notify_fail("ʥ����������������������������������ϣ��Թ����޸�����֮������޵ã�\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ����������������������ʥ���񹦡�\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("ʥ���񹦽����������ϣ���Υ��������徻֮�⣬"
		                   +RANK_D->query_respect(me)+"���޴˹������������\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("�����������̫���ˣ��޷����������ʥ���񹦡�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("�����������̫���ˣ��޷����������ʥ���񹦡�\n");
	}

	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="jiuyang-shengong") continue;
		if (sname[i]=="shenghuo-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧʥ���񹦣���\n");
	}
	return 1;

}

int practice_skill(object me)
{
	return notify_fail("ʥ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shenghuo-shengong/" + func;
}
