inherit SKILL;

mapping *action = ({
([	"action" : "$N双掌交错,一招「无情」，左掌虚探，右掌聚力拍向$n的头部",
	"force" : 130,
	"dodge" : 20,
	"damage" : 60,
	"lvl" : 0,
	"skill_name" : "无情",
	"damage_type" : "击伤"
]),
([	"action" : "$N凝神聚气，一招「无意」，掌风如细雨般向$n的$l扫去",
	"force" : 150,
	"dodge" : 10,
	"damage" : 80,
	"lvl" : 20,
	"skill_name" : "无意",
	"damage_type" : "震伤"
]),
([	"action" : "$N一招「无泪」，双掌幻化为一片花影，将$n笼罩于花影之内。",
	"force" : 150,
	"dodge" : 30,
	"damage" : 95,
	"lvl" : 30,
	"skill_name" : "无泪",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N身形凌空飞起，一招「无痕」，向$n的$l连击数掌",
	"force" : 200,
	"dodge" : 25,
	"damage" : 180,
	"lvl" : 40,
	"skill_name" : "无痕",
    "damage_type" : "瘀伤"
]),
([	"action" : "$N内气上提，一招「无命」，只见双掌灌满劲力斜斜攻向$n",
	"force" : 250,
	"dodge" : 20,
	"damage" : 200,
	"lvl" : 40,
	"skill_name" : "无命",
	"damage_type" : "瘀伤"
]),

([	"action" : "只见$N不经意的使出一招「无命」击向$n,$n慌忙招架，却见$N双掌一翻/n
为之精妙，实乃绝情掌的最高境界,一招「无休」急急攻向$n的破绽",
	"force" : 300,
	"dodge" : 25,
	"damage" : 250,
	"lvl" : 60,
	"skill_name" : "无休",
            "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ||usage=="unarmed" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练绝情掌必须空手。\n");
	if ((int)me->query_skill("mingyu-shengong", 1) < 120)
		return notify_fail("你的冥雨神功火候不够，无法学绝情掌。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练绝情掌。\n");
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
        int i, level;
	level   = (int) me->query_skill("jueqing-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练绝情掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueqing-zhang/" + action;
}