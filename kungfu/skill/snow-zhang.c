// snow-zhang.c
#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
    ([  "action":       "$N一招"+(order[random(13)])+"「梅林小酌」"NOR"，双手挥洒自如,轻飘飘地点向$n$l", 
        "parry": -10,
        "force": 40,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N左拳平削,右拳自下划了个半弧,一招"+(order[random(13)])+"「梅妻鹤子」"NOR",疾取$n的$l",
        "dodge": 10,
        "force": 50,
        "damage_type": "瘀伤"
    ]),
    ([  "action":     "$N一招"+(order[random(13)])+"「急雪落梅」"NOR",双掌如风中劲草,疾如流星般拍向$n$l",
        "dodge": 10,
        "force": 60,
        "parry": 5,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N信手一招"+(order[random(13)])+"「霜雪漫天」"NOR",散出森森寒气,罩向$n的$l",
        "dodge": 20,
        "parry": 10,
        "force": 80,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N使一招"+(order[random(13)])+"「余雪残梅」"NOR"，身随意转,随手拍向$n$l",
        "dodge": 10,
        "parry": 20,
        "force": 100,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N长身一笑,纵身而起,一式"+(order[random(13)])+"「寒江飘梅」"NOR"，围绕$n的$l轻飘飘接连出掌",
        "dodge":  10,
        "force": 140,
        "damage_type": "瘀伤"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练飞雪映梅掌必须空手。\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练习。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
        me->receive_damage("qi", 10);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"snow-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if ( me->query("family/family_name")== "凌霄城" && me->query_skill("bingxue-xinfa",1)>40) {
if (random(5)>3 && random(me->query_skill("bingxue-xinfa",1))>100)
{
victim->apply_condition("ice_poison", (me->query_skill("bingxue-xinfa"))/10 + victim->query_condition("ice_poison"));	
        return HIW "$n只觉得伤口一寒,一股寒气似冰箭一样的串进$n的全身。\n" NOR;
}
}
}
