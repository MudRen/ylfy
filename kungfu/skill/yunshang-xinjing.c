// yunshang-xinjing.c 云裳心经
// By suimeng
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("yunshang-xinjing", 1);
    if ( me->query("gender") == "无性" && me->query("gender") == "男性")
        return notify_fail("云裳心经只有女性才可以学习。\n");
    if (me->query_skill("force",1) <=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (me->query_skill("force",1)<100)
        return notify_fail("你的基本内功基础不够，怎能学云裳心经。\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="yunshang-xinjing") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("你不先散了别派内功，怎能学云裳心经？！\n");
    }
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    string msg;
	object weapon;
	weapon = victim->query_temp("weapon");
        if (me->query_skill("yunshang-xinjing",1) > 1000)
        if( random(me->query("neili")) > random(victim->query("neili")) && random(3)==0)
        {
            msg = "$N"HIR"舞起曼华绝伦的舞姿，$n迷离于其中，停下了一切行动.........\n" NOR;
                victim->apply_condition("no_perform", 3);
                victim->apply_condition("no_enforce", 3);
                victim->apply_condition("no_exert", 3);
				victim->apply_condition("no_equip", 10);
				
				if (weapon)weapon->unequip();
                return msg;
        }
}
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int damage2, j;
	damage2= (int) me->query("neili",1)/8+1000;
	if (random(5)==0 && me->query_skill("yunshang-xinjing",1)>=300  )
    {
    if (me->query("qi") <= me->query("max_qi"))
    {
    me->add("qi",damage2);
    }
   if (me->query("eff_qi") <= me->query("max_qi"))
    {
   me->add("eff_qi",damage2);
    }
  msg = HIB "$N" HIR "运起云裳心经，若凤鸣、若蝶舞、若莺啼、若雨滴!!\n" NOR;
        ob->apply_condition("no_perform", 1);
           message_vision(msg, me, ob);
           return j;
}       
}
int practice_skill(object me)
{
    return notify_fail("云裳心经只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"yunshang-xinjing/" + func;
}

