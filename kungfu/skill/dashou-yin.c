// dashou-yin.c 密宗大手印
#include <ansi.h>;
inherit SKILL;

mapping *action = (
{
([      "action" : "$N使出一招「莲花合掌印」，双掌合十，直直撞向$n的前胸",
"skill_name" : "莲花合掌印",
	"force" : 100,
	"dodge" : 0,
	"damage" : 200,
	"lvl" : 0,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「合掌观音印」，飞身跃起，双手如勾，抓向$n的$l",
"skill_name" : "合掌观音印",
	"force" : 200,
	"dodge" : 10,
	"damage" : 200,
	"lvl" : 8,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「准提佛母印」，运力于指，直取$n的$l",
"skill_name" : "准提佛母印",
	"force" : 250,
	"dodge" : 5,
	"damage" : 300,
	"lvl" : 16,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「红阎婆罗印」，怒吼一声，一掌当头拍向$n的$l",
"skill_name" : "红阎婆罗印",
	"force" : 300,
	"dodge" : 5,
	"damage" : 300,
	"lvl" : 24,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「药师佛根本印」，猛冲向前，掌如游龙般攻向$n",
"skill_name" : "药师佛根本印",
	"force" : 350,
	"dodge" : 5,
	"damage" : 200,
	"lvl" : 32,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「威德金刚印」，伏身疾进，双掌自下扫向$n的$l",
"skill_name" : "威德金刚印",
	"force" : 400,
	"dodge" : 5,
	"damage" : 100,
	"lvl" : 40,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「上乐金刚印」，飞身横跃，双掌前后击出，抓向$n的咽喉",
"skill_name" : "上乐金刚印",
	"force" : 450,
	"dodge" : 10,
	"damage" : 100,
	"lvl" : 48,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「六臂智慧印」，顿时劲气弥漫，天空中出现无数掌影打向$n的$l",
"skill_name" : "六臂智慧印",
	"force" : 500,
	"dodge" : 5,
	"damage" : 100,
	"lvl" : 56,
"damage_type" : "瘀伤",
	 ]),
});
int practice_level()
{
	return 56;
}
int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练密宗大手印必须空手。\n");
	else if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("dashou-yin", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	        (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");

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
	level   = (int) me->query_skill("dashou-yin",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练密宗大手印必须空手。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够，练不了密宗大手印。\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dashou-yin/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j,skill, neili;
	int level;

	level= (int) me->query_skill("longxiang",1);
	skill = me->query_skill("longxiang", 1);
	neili = me->query("neili");
	
	if ( level<= 0) level= (int) me->query_skill("xiaowuxiang",1);
	damage = (int) ob->query("neili",1)/10;
	if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
	{
		j = -damage/2;
		if (damage> 5000)	damage=5000;
		if (damage < 0 ) damage=0;
		msg = HIM"$N 口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强。$n心神一乱，内力尽然提不起来！\n"NOR;
		ob->set_temp("apply/attack", 0);
		ob->set_temp("apply/defense", 0);
		if (random(2)==0)
		{
			msg += HIM"$N"+HIM+"默念大明六字真言，手结摩利支天愤怒印! $n心神一荡，吐出一口鲜血!"+NOR;
			if (ob->query("qi") > damage)
			{
				ob->receive_damage("qi", damage/2);
				ob->receive_wound("qi", damage/2);
			}
			if (!ob->is_busy() && random(3)==0) ob->start_busy(2);
		}

		message_vision(msg, me, ob);
		return j;
	}
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(  me->query("jiali") > me->query_skill("force") && me->query_skill_mapped("force") == "longxiang")

		if (damage_bonus <10) damage_bonus=10;
	if( random(me->query_skill("dashou-yin",1)) > 150  || random(8)==0)
	{
		victim->receive_wound("qi", damage_bonus+30);
		return HIR "$N右手摆在胸前，中指微曲，拇指搭在中指侧，其余三指展开如莲花初放，念道：“叭”，只见淡淡的红光包围$n。！\n" NOR;
	}
}