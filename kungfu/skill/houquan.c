// houquan.c 猴拳

#include <ansi.h>
inherit SKILL;
string *xue_name = (
{
	"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
	"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

mapping *action = (
{
([	"action" : "\n$单腿微曲，忽的向前扑出，一式「仙猴摘桃」，二爪直出，抓向$n的双眼",
	"force" : 180,
	"dodge" : 15,
	"damage": 190,
"damage_type" : "抓伤",
	"lvl" : 0,
"skill_name" : "横空出世"
	 ]),
([	"action" : "$N左手虚晃，一式「灵猴攀枝」，右手直击，反扣$n的肩井大穴",
	"force" : 200,
	"dodge" : 20,
	"damage": 190,
	"lvl" : 8,
"skill_name" : "灵猴攀枝",
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N一臂前伸，一臂后指，一式「猿臂轻舒」，攻向$n的两肋",
	"force" : 230,
	"dodge" : 30,
	"damage": 195,
	"lvl" : 15,
"skill_name" : "猿臂轻舒",
"damage_type" : "瘀伤"
	 ]),
([	"action" : "\n$N忽然缩成一团，使一式「八方幻影」，双掌无形无定，一爪抓向$n的胸口",
	"force" : 230,
	"dodge" : 45,
	"damage": 160,
	"lvl" : 15,
"skill_name" : "八方幻影",
"damage_type" : "内伤"
	 ]),
([	"action" : "$N猛吸一口气，一弯腰，使一式「水中揽月」，双爪疾扣向$n的小腹",
	"force" : 220,
	"dodge" : 65,
	"damage": 180,
"damage_type" : "瘀伤",
	"lvl" : 20,
"skill_name" : "水中揽月"
	 ]),
([	"action" : "$N猛的向上高高跃起，一式「落地摘星」，居高临下，一爪罩向$n的头骨",
	"force" : 240,
	"dodge" : 80,
	"damage": 230,
"damage_type" : "抓伤",
	"lvl" : 30,
"skill_name" : "落地摘星"
	 ]),
});
int practice_level()
{
	return 30;
}
int valid_enable(string usage)
{
	return usage=="parry"|| usage=="unarmed";
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练猴拳必须空手。\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学猴拳。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练猴拳。\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("houquan", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
	mapping a_action;
	level   = (int) me->query_skill("houquan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		{
			a_action = action[NewRandom(i, 20, level/5)];
			break;
		}
	a_action["dodge"]  = 0-level/3;
	a_action["parry"]  = 0-random(level/3);
	a_action["damage"] = level;
	return a_action;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练猴拳必须空手。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练猴拳。\n");
	me->receive_damage("qi", 15);
	me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"houquan/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;
	lvl = me->query_skill("houquan", 1);

	if (damage_bonus < 100 || lvl < 150) return 0;
	if (me->query_skill_mapped("force") != "yunlong-shengong" )
		return;
	if (random(4)==0)
	{
		victim->receive_wound("qi", (damage_bonus ) / 3, me);
		return HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是肋骨断折的声音。\n" NOR;
	}
}
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j;
	int level2,damage2;

	level2= (int) me->query_skill("yunlong-shengong",1);

	damage2= (int) ob->query("neili",1)/10;
	if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		msg = HIR"$N"+HIR+"$N左手聚成虎爪状! 「凝血神抓」一把抓住$n的"+ xue_name[random(sizeof(xue_name))] +NOR;
		message_vision(msg, me, ob);
		if (ob->query("qi") > damage2)
		{
			ob->apply_condition("zhua_poison",10);
			ob->receive_damage("qi", damage2/2);
			ob->receive_wound("qi", damage2/2);
		}
		if (!ob->is_busy() && random(3)==0) ob->start_busy(2);
	}

	return j;
}
