#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int t = 1, i;
    int lvl = (int)me->query_skill("huaxue-dafa", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的化血大法。\n");
    if(lvl<=100)
    {
        if (lvl > 10 && -(int)me->query("shen") < t * 60) 
            return notify_fail("学化血大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
    }
    else
    {
        if (-(int)me->query("shen") < (51200 + (lvl - 100) * 500)) 
            return notify_fail("学化血大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
    }
	
	if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功火候还不够，无法领会化血大法。\n");
    
	skl = me->query_skills();    
	sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学化血大法？\n");
    }

    return 1;
}

int practice_skill(object me)
{
        return notify_fail("化血大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

