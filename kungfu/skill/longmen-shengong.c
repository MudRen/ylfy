// made by lks;

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("longmen-shengong", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的化血大法。\n");

	 if ( me->query("class") == "bonze" )
        return notify_fail("龙门神功讲究杀气御敌，有违佛家之意，"+RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	 if( (int)me->query_skill("longmen-shengong", 1) > 30 )
		return notify_fail("龙门神功只能通过领悟来提高。\n");

	if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功火候还不够，无法领会龙门神功。\n");
    
	skl = me->query_skills();
    
	sname  = keys(skl);
    
	for (i=0;i<sizeof(skl);i++){
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学龙门神功？\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("龙门神功不能通过练习来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longmen-shengong/" + func;
}
