// yunv-xinfa.c 玉女心法

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

	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳难调，不能修习玉女心法。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="yunv-xinfa") continue;
		if (sname[i]=="yunv-xinjing") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学玉女心经？！\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("玉女心法只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}

