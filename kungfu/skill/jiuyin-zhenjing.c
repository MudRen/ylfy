// jiuyin-zhenjing.c 九阴真经

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyin-zhenjing", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的九阴真经。\n");
    if (me->query_skill("force",1) <=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("你的基本内功基础不够，怎能学九阴真经。\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="jiuyin-zhenjing") continue;
        if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("你不先散了别派内功，怎能学九阴真经？！\n");
    }
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    string msg;	
	
    if( damage_bonus < 100 ) return 0;
	
		if (me->query_skill("jiuyin-zhenjing",1) > 550)		
		 
        if( random(me->query("max_neili")) > random(victim->query("max_neili")) &&random(3)==0)
        {
            msg = "$n"HIB"忽然感觉到$N一股阴柔的内力侵入体内\n" NOR;
                victim->receive_wound("qi", damage_bonus);
                //victim->add("jing", -extra);
				victim->apply_condition("no_perform", 1);
				victim->apply_condition("no_enforce", 1);			             
                return msg;
        }
}
int practice_skill(object me)
{
    return notify_fail("九阴真经只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"jiuyin-zhenjing/" + func;
}

