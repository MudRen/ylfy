//shayi-xinfa 杀意心法

#include <ansi.h>
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
	int lvl = (int)me->query_skill("shayi-xinfa", 1);
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");
	if (me->query_skill("force",1)<=lvl)
		return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
	if (me->query_skill("force",1)<30)
		return notify_fail("你的基本内功基础不够，怎能学杀意心法。\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="shayi-xinfa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="yijing-force") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学杀意心法？！\n");
	}
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("杀意心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"shayi-xinfa/" + func;
}

mapping exercise_msg(object me)
{
	return ([
            "status_msg" : HIB + me->name()+"杀意四起，眼神凌厉。" NOR,
            "start_my_msg" : HIR"眼神变得凌厉，四周杀意四起，真气开始在体内运转。\n"NOR,
            "start_other_msg" : me->name()+"全身收缩，全部的力量发挥了出来，眼神中的杀意无比凌厉。\n",
            "halt_msg" : "$N眉头松展，杀意消失，恢复了平时的模样。\n",
            "end_my_msg" : "无尽的杀意缓缓散入全身，睁开眼，长吐了一口气。\n",
            "end_other_msg" : "只见"+me->name()+"的眼睛允满杀意，但马上又恢复了原状。\n"
	        ]);
}
