
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
    int lvl = (int)me->query_skill("yiqiguan-riyue", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的一气贯日月。\n");
    if(lvl<=100)
    {
        if (lvl > 10 && (int)me->query("shen") < t * 20) 
            return notify_fail("你的侠义正气太低了，难以领会高深的一气贯日月。。\n");
    }
    else
    {
        if ((int)me->query("shen") < (51200 + (lvl - 100) * 2000)) 
            return notify_fail("你的侠义正气太低了，难以领会高深的一气贯日月。。\n");
    }
   
   if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功火候还不够，无法领会一气贯日月。\n");
    
	skl = me->query_skills();
    
	sname  = keys(skl);
    
	for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="huagong-dafa") continue;
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学一气贯日月？！\n");
    }

    return 1;
}

int practice_skill(object me)
{
        return notify_fail("一气贯日月只能用学(learn)的来增加熟练度。\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("yiqiguan-riyue",1))
        {
                case 50:
                {
                        message_vision(HIY "$N的额头似乎比以前亮堂了不少。看来，功力提升了一个层次。\n" NOR, me);
                        tell_object(me, HIY "由于你的勤学苦练，你可以发出指镖御敌了！！\n\n" NOR);
                        break;
                }
                case 100:
                {
                        message_vision(HIC "你突然发现$N的太阳穴明显的突起了。想必$N的功力又有所精进。\n" NOR, me);
                        tell_object(me, HIC "由于你对一气贯日月的进一步领悟，你可以发出“从心所欲”的内劲了！！\n\n" NOR);
                        me->set("yiqiguan-riyue",1);
                        break;
                }
                case 150:
                {
                        message_vision(HIW "$N的太阳穴从突起的状态又恢复原样，和常人一样。看来$N的功力已经还璞归真了。\n" NOR, me);
                        tell_object(me, HIW "由于你对一气贯日月的更进一步领悟，你可以发出“登峰造极”的内劲了！！\n\n" NOR);
                        me->set("yiqiguan-riyue",2);
                        break;
                }

        }
        return;
}

string exert_function_file(string func)
{
        return __DIR__"yiqiguan-riyue/" + func;
}

