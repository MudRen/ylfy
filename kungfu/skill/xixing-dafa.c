// xixing-dafa.c 吸星大法
// By suimeng
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
  
    int lvl = (int)me->query_skill("xixing-dafa", 1);
    if ( me->query("gender") == "无性")
        return notify_fail("你无根无性，阴阳不调，难以领会吸星大法。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("你的基本内功基础不够，怎能学吸星大法。\n");
    if ( me->query_skill("kuihua-xinfa",1) || me->query_skill("beiming-shengong",1)|| me->query_skill("huagong-dafa",1))
		return notify_fail("你不先散了别派内功，怎能学吸星大法？！\n");
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("吸星大法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"xixing-dafa/" + func;
}

int help(object me)
{
        write(HIC"\n吸星大法："NOR"\n");
        write(@HELP

    日月神教黑木崖的一种内功。

    吸星大法创自北宋年间的逍遥派，分为北冥神功和化功大法两
路，后来从大理段氏和星宿派分别传落，合而为一，称为吸星大法。
主要是继承了化功大法一路，修习者当令丹田常如空箱，恒似深谷，
空箱可贮物，深谷可容水。若有内息，散之于任脉诸穴。
    吸星大法只能拜任我行为师学习，非有相当机缘不能学到。

        学习要求：
                基本内功100级

HELP
        );
        return 1;
}
