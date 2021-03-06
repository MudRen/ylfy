// marry 99.8
inherit SKILL;
#include <ansi.h>
mapping *action = ({
    ([  "action":       "$N使一招「"HIM"痴心一片"NOR"」，双拳飘移不定击向$n$l",
        "dodge": 10,
        "parry": -10,
        "force": 50,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N倏忽欺至$n身前，一招「"HIB"妄想成狂"NOR"」直拍$n的$l",
        "dodge": 20,
        "parry": -10,
        "force": 100,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N身形绕$n一转，一招「"HIY"临渊羡鱼"NOR"」向$n$l接连出拳",
        "dodge": 30,
        "parry": -10,
        "force": 200,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N身形拔起，在半空一招「"MAG"难言之隐"NOR"」右掌猛击$n的$l",
        "dodge": -10,
        "parry": -10,
        "force": 350,
        "damage_type": "瘀伤"
        ]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练痴心妄想拳必须空手。\n");
        if ((int)me->query("max_neili") < 1000)
        return notify_fail("你的内力太弱，无法练痴心妄想拳。\n");
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
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"cxwx-quan/" + action;
}
