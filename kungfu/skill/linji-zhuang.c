// linji-zhuang.c 临济十二庄

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

    if ( (me->query("family/family_name") != "峨嵋派"))
        return notify_fail("你不是峨嵋弟子，怎能修习临济十二庄。\n");
				    
    if ( me->query("gender") == "无性" )
        return notify_fail("你无根无性，阴阳不调，难以领会纯正、高深的佛门内功心法。\n");

    if ((int)me->query_skill("force", 1) < 20)
        return notify_fail("你的基本内功火候还不够，无法领会临济十二庄。\n");

        skl = this_player()->query_skills();	
        sname  = keys(skl);	
      for (i=0;i<sizeof(skl);i++){	
        if (sname[i]=="yijing-force") continue;	
        if (sname[i]=="linji-zhuang") continue;	
		if (sname[i]=="xixing-dafa") continue;
        if( SKILL_D(sname[i])->valid_enable("force") )	
	         return notify_fail("你不先散了别派内功，怎能学临济十二庄？！\n");
}
	return 1;
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}
