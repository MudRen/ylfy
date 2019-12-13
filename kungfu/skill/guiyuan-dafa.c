// guiyuan-dafa 归元大法
// modify by lyy 2016-6-27
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
	int z = (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < z / 10; j++) t *= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if ( me->query("gender") == "无性" && me->query_skill("guiyuan-dafa",1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的归元大法。\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="guiyuan-dafa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学归元大法？！\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
    if( damage_bonus < 600 ) return 0;
   if( random(5*(me->query_skill("guiyuan-dafa",1))) > (damage_bonus )) {
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali")/4);
						msg = HIR"$N运起神功气息内敛归元真气一收一放顿时" + HIB + BLINK"一缕三分归元真气" + NOR + HIW"震伤了$n的" + HIR"奇经八脉！！\n" NOR;
						//return sprintf(msg + CYN"($N的归元大法特效对$n" + CYN + "造成" + damage_bonus + "点精伤害)\n", me, victim);
						return msg;
        }
}

int practice_skill(object me)
{
	return notify_fail("归元大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"guiyuan-dafa/" + func;
}
