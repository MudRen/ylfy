// 蝶翼剑法
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$N手中$w轻轻点向$n的$l，迅疾无比",
        "force"  : 100,
        "dodge"  : 10,
        "damage" : 170,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长跃而起，手中的$w挽了一个剑花，猛然刺向$n",
        "force"  : 120,
        "dodge"  : 15,
        "damage" : 284,
        "lvl"    : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出回身侧步，手中的$w斜刺$n的$l",
        "force"  : 140,
        "dodge"  : 30,
        "damage" : 300,
        "lvl"    : 50,
        "damage_type" : "内伤"
]),
([      "action" : "$N却身提步，手中的$w似挡飞挡，似进非进，忽的直刺$n",
        "force"  : 160,
        "dodge"  : 38,
        "damage" : 310,
        "lvl"    : 75,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w颤动的极快，只幌得$n眼花撩乱，浑不知从何攻来",
        "force"  : 180,
        "dodge"  : 45,
        "damage" : 325,
        "lvl"    : 100,
        "damage_type" : "内伤"
]),
([      "action" : "$N剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l",
        "force"  : 200,
        "dodge"  : 50,
        "damage" : 330,
        "lvl"    : 130,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w由内自外一刺，没有任何花巧，然而来是快得不可思议",
        "force"  : 220,
        "dodge"  : 55,
        "damage" : 440,
        "lvl"    : 160,
        "damage_type" : "刺伤"
]),
([      "action" : "$N轻叹一声，手中的$w化作一到长弧点向$n",
        "force"  : 240,
        "dodge"  : 70,
        "damage" : 550,
        "lvl"    : 200,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一抖手中的$w，挽出数个剑花，笼罩了$n",
        "force"  : 260,
        "dodge"  : 85,
        "damage" : 555,
        "lvl"    : 225,
        "damage_type" : "刺伤"
]),
([  "action" : "$N一声轻笑，手中$w幻化作满天星点，不知刺向$n的何处",
        "force"  : 320,
        "dodge"  : 90,
        "damage" : 780,
        "lvl"    : 250,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query_skill("wudie-xinjing", 1) < 50)
		return notify_fail("你的「舞蝶心经」火候不够，无法学「蝶翼剑法」。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练「蝶翼剑法」。\n");
	if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
		return notify_fail("由于你的天性不够，你永远无法学到「蝶翼剑法」。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("dieyi-jianfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练「蝶翼剑法」。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练「蝶翼剑法」。\n");
	me->receive_damage("qi", 30);
	me->add("neili",-15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dieyi-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( userp(victim) )
	{
		if( random(me->query("jiali")) * 2 > victim->query("jiali")) return 0;

		victim->receive_wound("qi", random( me->query("jiali")));
		return MAG BLINK "你听到「唰」一声轻响好似凉风吹过，忽然间$n血冒三丈，被剑气所伤！\n" NOR;
	}
	else
	{
		if( damage_bonus < 1 ) return 0;

		if( random( me->query_skill("sword") ) > random( victim->query_skill("force")) && me->query_skill_mapped("force") == "wudie-xinjing" )
		{
			victim->receive_wound("qi", damage_bonus );
			return MAG BLINK "你听到「唰」一声轻响好似凉风吹过，忽然间$n血冒三丈，被剑气所伤！\n" NOR;
		}
	}
}