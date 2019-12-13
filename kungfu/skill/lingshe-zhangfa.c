//lingshe_zhangfa.c 灵蛇杖法
#include "ansi.h"
inherit SKILL;
mapping *action = (
{
([  "action": "$N使出一招「"+RED+"灵蛇出洞"+NOR+"」，手中$w大开大阖扫向$n的$l",
	"force" : 100,
	"lvl" : 0,
"skill_name" : RED "灵蛇出洞" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N手中$w阵阵风响，一招「"+MAG+"摇头摆尾"+NOR+"」向$n的$l攻去",
	"force" : 140,
	"lvl" : 20,
"skill_name" : MAG "摇头摆尾" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N举起$w，居高临下使一招「"+HIW+"灵蛇下"+BLU+"涧"+NOR+"」砸向$n的$l",
	"force" : 180,
	"lvl" : 30,
"skill_name" : HIW "灵蛇下涧" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N一招「"+YEL+"灵蛇挺身"+NOR+"」，手中$w猛烈扫向$n的$l",
	"force" : 220,
	"lvl" : 40,
"skill_name" : YEL "灵蛇挺身" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N使出一招「"+YEL+"蛇游蟒走"+NOR+"」，$w左右迂回向$n的$l扫去",
	"force" : 260,
	"lvl" : 50,
"skill_name" : YEL "蛇游蟒走" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N手中$w一挥，使出一招「"+BLU+"蛇缠左右"+NOR+"」，忽左忽右扫向$n的$l",
	"force" : 300,
	"lvl" : 60,
"skill_name" : BLU "蛇缠左右" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N使出一招「"+RED+"巨蟒下"+YEL+"山"+NOR+"」，高举手中$w，劈头砸向$n的$l",
	"force" : 340,
	"lvl" : 80,
"skill_name" : RED "巨蟒下山" NOR,
"damage_type": "挫伤"
	 ]),
([  "action": "$N使出一招「"+RED+"灵蛇出"+BLK+"洞"+NOR+"」，手中$w猛一探，直扫$n的$l",
	"force" : 380,
	"lvl" : 100,
"skill_name" : RED "灵蛇出洞" NOR,
"damage_type": "挫伤"
	 ]),
});
int practice_level()
{
	return 100;
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
	level   = (int) me->query_skill("lingshe-zhangfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		{
			a_action = action[NewRandom(i, 20, level/5)];
			break;
		}
	a_action["dodge"]  = 0-level/2;
	a_action["parry"]  = 0-level/2;
	a_action["attack"]  = level/2;
	a_action["damage"] = level/2;
	return a_action;

}

int valid_enable(string usage)
{
	return (usage == "staff") || (usage == "parry");
}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的内力不够。\n");
	if (me->query_skill("staff", 1) <=me->query_skill("lingshe-zhangfa", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "staff")
		if (!objectp(weapon = me->query_temp("secondary_weapon"))
		        || (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练灵蛇杖法。\n");
	me->receive_damage("qi", 20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl,flvl;
	int level;
	object target;
	target=victim;
	level = (int) me->query_skill("hamagong",1);
	lvl = me->query_skill("lingshe-zhangfa",1);
	flvl = me->query_skill("lingshe-zhangfa",1);


	if (flvl * 2 + random(lvl) > victim->query_skill("force") && random(5)==0)
	{
		if (lvl < 80 || flvl < 10 || ! damage_bonus)
			return;
		if (!me->query_temp("weapon") )
			return;
		victim->apply_condition("snake_poison",20);
		victim->add("eff_qi",-random(lvl)+1);
		return HIR "只听$n痛呼了一声，却是被蛇杖顶端的小蛇咬了个正着！\n" NOR;
	}

	if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
	{
		target->apply_condition("snake_poison",5);
		target->apply_condition("chanchu_poison",5);
		target->apply_condition("qx_snake_poison",3);
		if (!target->is_busy()) target->start_busy(2);
		return HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出!$n头一昏，不知所措 ！\n";
	}

	if( random(me->query_skill("hamagong",1)) > 100 )
	{
		victim->apply_condition("snake_poison", random(me->query_skill("hamagong",1)/10) + 1 +
		                        victim->query_condition("snake_poison"));
		tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
		tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
	}
	if (me->query_temp("hmg_dzjm") && random(2)==0 )
	{
		victim->receive_damage("qi", damage_bonus/2);
		victim->receive_wound("qi", damage_bonus/2);
		return HIR "$N倒转经脉对着$n张口一咬!$n伤口一凉，鲜血喷出！\n";
	}

}
string perform_action_file(string action)
{
	return __DIR__"lingshe-zhangfa/" + action;
}