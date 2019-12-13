// iceforce.c2
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("iceforce", 1);
    if ( me->query("gender") != "女性")
        return notify_fail("意寒神功是一种阴柔的内功，只适合女性学。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("你的基本内功基础不够，怎能学意寒神功。\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="iceforce") continue;
        if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("你不先散了别派内功，怎能学意寒神功？！\n");
    }
    return 1;
}
int practice_skill(object me)
{
        return notify_fail("意寒功只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"iceforce/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("iceforce")) > (damage_bonus + foo) ) {
                        victim->receive_wound("qi", (damage_bonus + foo));
                        victim->apply_condition("iceshock", factor/3);
                        return "$N的招式挟著一股阴寒无比的劲风使得$n不禁打了个寒噤。\n";
                }
        }
        return foo;
}
 