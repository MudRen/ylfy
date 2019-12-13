// wuji-shengong.c 无极神功

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
		return notify_fail("你的基本内功火候还不够。\n");

	if ( me->query("gender") == "无性" && me->query_skill("wuji-shengong",1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的无极神功。\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="wuji-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学无极神功？！\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("无极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"wuji-shengong/" + func;
}
