// xiuluo-dao.c 修罗刀
inherit SKILL;
mapping *action = ({
([  "action" : "$N藏刀内收，一招「"+YEL+"割肉饲鹰"+NOR+"」，刀锋自下而上划了个半弧，向$n的$l挥去",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "割肉饲鹰" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N左掌虚托右肘，一招「"+RED+"投身饿虎"+NOR+"」，手中$w笔直划向$n的$l",
    "force" : 130,
    "lvl" : 12,
    "skill_name" : RED "投身饿虎" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+BLU+"斫头谢天"+NOR+"」，$w绕颈而过，刷地一声自上而下向$n猛劈",
    "force" : 140,
    "lvl" : 18,
    "skill_name" : BLU "斫头谢天" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N右手反执刀柄，一招「"+HIC+"折骨出髓"+NOR+"」，猛一挫身，$w直向$n的颈中斩去",
    "force" : 160,
    "lvl" : 24,
    "skill_name" : HIC "折骨出髓" NOR,
    "damage_type" : "割伤",
]),
([  "action" : "$N一招「"+HIW+"挑身千灯"+NOR+"」，无数刀尖化作点点繁星，向$n的$l挑去",
    "force" : 180,
    "lvl" : 30,
    "skill_name" : HIW "挑身千灯" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N双手合执$w，一招「"+RED+"挖眼布施"+NOR+"」，拧身急转，刀尖直刺向$n的双眼",
    "force" : 210,
    "lvl" : 36,
    "skill_name" : RED "挖眼布施" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+RED+"剥皮书经"+NOR+"」，手中$w划出一个大平十字，向$n纵横劈去",
    "force" : 240,
    "lvl" : 42,
    "skill_name" : RED "剥皮书经" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N反转刀尖对准自己，一招「"+HIB+"剜心决志"+NOR+"」，全身一个翻滚，$w向$n拦腰斩去",
    "force" : 280,
    "lvl" : 48,
    "skill_name" : HIB "剜心决志" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIR+"烧身供佛"+NOR+"」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
    "force" : 320,
    "lvl" : 54,
    "skill_name" : HIR "烧身供佛" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N刀尖平指，一招「"+RED+"刺血满地"+NOR+"」，一片片切骨刀气如飓风般裹向$n的全身",
    "force" : 370,
    "lvl" : 60,
    "skill_name" : RED "刺血满地" NOR,
    "damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="damo-jian"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你必须要先弄把刀来。\n");

    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("xiuluo-dao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学修罗刀。\n");
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
        level   = (int) me->query_skill("xiuluo-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练修罗刀。\n");
    me->receive_damage("qi", 35);
    return 1;
}
