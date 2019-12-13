#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = (
{
([      "action": "$N双拳一错，一招“魔火天焚”幻出漫天拳影拢向$n的$l",
	"dodge":   30,
	"parry":   10,
	"damage":  250,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N双拳纷飞，一招“魔王食飧”直取$n的$l",
	"dodge":   10,
	"parry":   30,
	"damage":  230,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N暴喝一声，双拳连环推出，一招“魔吼天地”强劲的拳风直扑$n的$l",
	"dodge":   30,
	"parry":   10,
	"damage":  250,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N使出如意地魔连环八拳中的“魔弑森森”，完全将$n的$l笼罩在双拳之下",
	"dodge":  10,
	"parry":  30,
	"damage": 260,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N化拳为刀，一招“乾坤尽魔”，左右拳分砍$n的两处要害",
	"dodge": 20,
	"parry":  30,
	"damage": 240,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N内气上提，全身拔起，一招“魔高和寡”，双拳凌空拍下",
	"dodge":  70,
	"parry":  10,
	"damage":  280,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N提气游走，一招“魔海漭漭”，森森拳风无孔不入般地击向$n的$l",
	"parry":  40,
	"force":  220,
"damage_type":  "瘀伤"
	 ]),
([      "action": "$N使出如意地魔连环八拳中的“璞宇浑魔”双拳携天地魔神之威击向$n的$l",
	"parry":  40,
	"force":  120,
	"damage" :  250,
"damage_type":  "瘀伤"
	 ]),

});

mapping query_action(object me)
{
	if (random(me->query_skill("unarmed")) > 60 && me->query_skill("force") > 50 && me->query("neili") > 100 )
	{
		me->add("neili", -100);
return ([    "action": HIY"只见$N拚尽全力，全身急疾飞旋，双拳豪光暴现，一股骇人的拳力攻向$n的胸前"NOR,
		             "parry": 60,
		             "dodge": 60,
		             "force": 600,
		             "damage" : 880,
             "damage_type": "瘀伤"
		        ]);
	}
	return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
	return usage=="parry" || usage=="cuff" || usage=="unarmed";
}
int valid_combine(string combo)
{
	return combo=="tianmo-zhang";
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天魔拳必须空手。\n");
	if ((int)me->query_skill("tianmo-shengong", 1) < 10)
		return notify_fail("你的天魔神功火候不够，无法练天魔拳。\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("你的内力太弱，无法练天魔拳");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("你的内力不够练天魔拳。\n");
	if (me->query_skill("tianmo-quan", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianmo-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	int level, level2, i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");

	level = (int) me->query_skill("kuihua-xinfa",1);
	level2= (int) me->query_skill("kuihua-xinfa",1);
	if (me->query_temp("weapon"))
		name = "手中" + weapon->name();
	else
		name = "双拳";
	if (!me->query_temp("action_flag") && random(3)==0 && level>=300 && me->query_skill_mapped("force") == "tianmo-shengong")
	{
		message_vision(HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
		               HIW "\n宛若流星般分从不同的方位同时攻向$n" HIW "！\n"
		               NOR, me, victim);
		me->set_temp("action_flag", 1);
		for (i = 0; i < 5; i++)
		{
			if (! me->is_fighting(victim))
				break;
			if (random(2)==0) victim->start_busy(2);
			COMBAT_D->do_attack(me, victim, weapon, 0);
		}
		me->delete_temp("action_flag");
	}
}

int ob_hit(object ob, object me, int damage)
{

	string msg;
	int j;
	int level,damage2;
	level = (int) me->query_skill("tianmo-shengong",1);

	damage2= (int) ob->query("neili",1)/8;
	if (random(4)==0 && level>=300 && me->query_skill_mapped("force") == "tianmo-shengong")
	{
		ob->add("neili",-damage2);
		me->add("neili",damage2);
		msg = HIC "$N" HIC "一声冷笑! 隔空吸功!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;

		message_vision(msg, me, ob);
		return j;
	}
}

