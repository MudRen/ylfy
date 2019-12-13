// wudie-xinjing.c 舞蝶心经
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
	if ( me->query("gender") == "男性")
		return notify_fail("你又不是女人，难以领会高深的舞蝶心经。\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的舞蝶心经。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("你的侠义正气太低了。\n");
	}
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("舞蝶心经只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"wudie-xinjing/" + func;
}

