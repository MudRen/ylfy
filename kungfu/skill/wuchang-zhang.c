// wuchang-zhang.c 无常杖法
inherit SKILL;
mapping *action = ({
([  "action":"$N微一躬身，一招「"+BLK+"庸人自扰"+NOR+"」，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : BLK "庸人自扰" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+RED+"想入非非"+NOR+"」，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
    "force" : 110,
    "lvl" : 7,
    "skill_name" : RED "想入非非" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+GRN+"六神不安"+NOR+"」，举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
    "force" : 120,
    "lvl" : 14,
    "skill_name" : GRN "六神不安" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+YEL+"面无人色"+NOR+"」，举起$w，呆呆地盯了一会，突然猛地一杖打向$n的$1",
    "force" : 130,
    "lvl" : 20,
    "skill_name" : YEL "面无人色" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N将$w顶住自己的胸膛，一端指向$n，一招「"+CYN+"心惊肉跳"+NOR+"」，大声叫喊着冲向$n",
    "force" : 140,
    "lvl" : 25,
    "skill_name" : CYN "心惊肉跳" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+HIC+"行尸走肉"+NOR+"」，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
    "force" : 150,
    "lvl" : 30,
    "skill_name" : HIC "行尸走肉" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N面带戚色，一招「"+HIW+"饮恨吞声"+NOR+"」，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
    "force" : 300,
    "lvl" : 35,
    "skill_name" : HIW "饮恨吞声" NOR,
    "damage_type":"瘀伤"
]),
([  "action":"$N一招「"+HIY+"力不从心"+NOR+"」，假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$l",
    "force" : 350,
    "lvl" : 40,
    "skill_name" : HIY "力不从心" NOR,
    "damage_type":"刺伤"
]),
([  "action":"$N伏地装死，一招「"+HIG+"穷途没路"+NOR+"」，一个翻滚，身下$w往横里打出，挥向$n的裆部",
    "force" : 400,
    "lvl" : 45,
    "skill_name" : HIG "穷途没路" NOR,
    "damage_type":"瘀伤"
]),
([  "action":"$N一招「"+HIB+"呆若木鸡"+NOR+"」，身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$l",
    "force" : 450,
    "lvl" : 50,
    "skill_name" : HIB "呆若木鸡" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N高举$w，一招「"+BLU+"人鬼殊途"+NOR+"」，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
    "force" : 500,
    "lvl" : 55,
    "skill_name" : BLU "人鬼殊途" NOR,
    "damage_type":"瘀伤"
]),
([  "action":"$N一招「"+MAG+"我入地狱"+NOR+"」，单腿独立，$w舞成千百根相似，根根砸向$n全身各处要害",
    "force" : 550,
    "lvl" : 60,
    "skill_name" : MAG "我入地狱" NOR,
    "damage_type":"瘀伤"
]),
});
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("wuchang-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学无常杖法。\n");

    return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuchang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练无常杖法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

