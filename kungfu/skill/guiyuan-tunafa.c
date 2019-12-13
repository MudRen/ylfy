// guiyuan-tunafa.c 铁掌帮 归元吐纳法

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

	if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候不足，不能学归元吐纳法。\n");
    if ( me->query("gender") == "无性" && me->query_skill("guiyuan-tunafa",1) > 49)	
        return notify_fail("你无根无性，阴阳不调，难以领会高深的归元吐呐法。\n");	
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学归元吐纳法做什麽！\n");

        skl = this_player()->query_skills();	
        sname  = keys(skl);	
    for (i=0;i<sizeof(skl);i++){	
        if (sname[i]=="yijing-force") continue; 	
        if (sname[i]=="guiyuan-tunafa") continue; 
        if (sname[i]=="xixing-dafa") continue;      	
        if( SKILL_D(sname[i])->valid_enable("force") )	
		    return notify_fail("你不先散了别派内功，怎能学归元吐纳法？！\n");
              }
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("归元吐呐法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"guiyuan-tunafa/" + func;
}
