#include <ansi.h>
#include <skill.h>

inherit SKILL;
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *xue_name = (
{
	"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
	"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

mapping *action = (
{
([      "action" : "$N右手食指微点，出招"+(order[random(13)])+"「晓天初阳」"NOR"，一股雄浑的一阳指力射向$n，出手沉稳，招数正大",
	"force" : 200,
	"damage" : 220,
"weapon" : "一阳指力",
	"parry" : 10,
	"dodge" : 15,
	"lvl" : 0,
"skill_name" : "晓天初阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N一指"+(order[random(13)])+"「日出霞光」"NOR"，激出的一股罡气涌向$n，看似是温淳平和，但沛然浑厚，无可与抗",
	"force" : 250,
	"parry" : 25,
	"dodge" : 20,
	"damage" : 250,
	"lvl" : 20,
"skill_name" : "日出霞光",
"damage_type" : "内伤"
	 ]),
([      "action" : "忽听嗤嗤轻响，一股柔和的气流自$N手指涌出，正是一招"+(order[random(13)])+"「阳春暖融」"NOR"，缓缓点向$n$l",
	"force" : 300,
	"parry" : 10,
	"dodge" : 10,
	"damage" : 245,
"weapon" : "一阳指力",
	"lvl" : 40,
"skill_name" : "阳春暖融",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N一步跨到$n身后，又如闪电般跃回，一式「鲁阳返日」，右手食指疾出，指向$n的$l",
	"force" : 430,
	"attack": 79,
	"dodge" : 65,
	"parry" : 35,
	"damage": 83,
	"lvl" : 60,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "鲁阳返日",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N左手轻扬，右手食指挟着雄浑内力疾点$n的$l，招式光明坦荡，正是一式「阳春白雪」",
	"force" : 460,
	"attack": 75,
	"dodge" : 91,
	"parry" : 85,
	"damage": 78,
	"lvl" : 80,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "阳春白雪",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N身影飘起，一式「阳钩挥天」，身形自上而下闪出，右手猛然劲点向$n的$l",
	"force" : 490,
	"attack": 105,
	"dodge" : 35,
	"parry" : 24,
	"damage": 98,
	"lvl" : 100,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "阳钩挥天",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N踏前一步，伸指凌空轻轻一点，$n只觉气息一紧，已被"+(order[random(13)])+"「赤日焦阳」"NOR"的刚阳气劲触到$l",
	"force" : 350,
	"parry" : 15,
	"dodge" : 25,
	"damage" : 280,
	"lvl" : 60,
"weapon" : "纯阳真气",
	"damage" : 240,
"skill_name" : "赤日焦阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N衣袖轻摆，罡阳柔气从袖底挥出，涌向$n的$l，正是玄功若神的一招"+(order[random(13)])+"「晓阳云暖」"NOR"",
	"force" : 400,
	"parry" : 25,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 80,
"skill_name" : "晓阳云暖",
"damage_type" : "内伤"
	 ]),
([      "action": "$N左掌斜削，突然间变掌为指，嗤的一式「丹凤朝阳」，使出一阳指力，疾点$n的$l",
	"force" : 528,
	"attack": 119,
	"dodge" : 24,
	"parry" : 23,
	"damage": 98,
	"lvl" : 180,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "丹凤朝阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N面带微笑，伸出右食指，缓缓点向$n胸口，这招"+(order[random(13)])+"「暮云映日」"NOR"劲气弥漫，却无丝毫破空之声",
	"force" : 450,
	"parry" : 15,
	"dodge" : 30,
	"damage": 350,
"weapon" : "一阳指力",
	"lvl" : 100,
"skill_name" : "暮云映日",
"damage_type" : "刺伤"
	 ]),
([      "action" : "只见$N食指微屈，一指"+(order[random(13)])+"「九天乾阳」"NOR"点出，气象森严，雍容肃穆，于威猛之中不脱王者风度！",
	"force" : 500,
	"parry" : 30,
	"dodge" : 30,
	"damage":485,
"weapon" : "纯阳真气",
	"lvl" : 110,
"skill_name" : "九天乾阳",
"damage_type" : "内伤"
	 ]),
([ "action" : HIW"$N头顶白气氤氲，渐聚渐浓，便似蒸笼一般，食指伸出，一式"+(order[random(13)])+"「三阳开泰」"NOR"按向$n！"NOR,
	"force" : 560,
	"parry" : 40,
	"dodge" : 30,
	"damage" : 500,
	"lvl" : 130,
"skill_name" : "三阳开泰",
"damage_type" : "震伤"
	 ])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="finger";
}
int practice_level()
{
	return 100;
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query_skill("kumu-shengong", 1) < 20)
		return notify_fail("你的枯木神功火候不够，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	if (me->query_skill("finger", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	return 1;
}

int valid_combine(string combo)
{
	return combo=="haotian-zhang";
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
	int level=me->query_skill("yiyang-zhi",1);
	mapping a_action = action[random( sizeof(action) )];
	a_action["dodge"]  = 0-level*2;
	a_action["parry"]  = 0-level*2;
	a_action["damage"] = level*2;
	return a_action;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string name,weapon;
	name = xue_name[random(sizeof(xue_name))];

	if (random(me->query_skill("yiyang-zhi", 1)) > 150
	        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
			&& me->query_skill_mapped("parry") == "yiyang-zhi"
	        && me->query_skill("kumu-shengong",1) > 50
	   )
	{
		if(!victim->is_busy()) victim->start_busy(3);
		victim->apply_condition("yyz_damage",30);
		victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
		return CYN "$n被$N点中"RED+name+CYN"，！\n" NOR;
	}

	if(me->query_skill("yiyang-zhi", 1) > 100
	        && me->query("neili") > 500
	        && me->query_skill_mapped("parry") == "yiyang-zhi"
	        && victim->query("neili") > 100
	        && me->query_skill("kumu-shengong",1) > 50)
	{
		victim->add("neili", -random(120));
	}
	if(victim->is_busy()) return 0;
	if (!objectp(weapon = me->query_temp("weapon")))
	{
		if((!random(5)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
		        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
				&& me->query_skill_mapped("parry") == "yiyang-zhi"
		        && me->query_skill("kurong-changong",1) > 50)
		{

			if( !victim->is_busy() )
			{
				victim->start_busy(3);
			}
			me->add("neili",-30);
			if (victim->query("neili") <=(damage_bonus/2+30))
				victim->set("neili",0);
			else
				victim->add("neili",-damage_bonus/2+50);
			victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			return CYN "$n被$N凌空一指点中"RED+name+CYN"，真气不由得一滞！\n" NOR;
		}
	}
	else
	{
		if((!random(4)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
		        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
		        && me->query_skill("kurong-changong",1) > 50)
		{
			if( !victim->is_busy() )
			{
				victim->start_busy(3);
			}
			me->add("neili",-30);
			victim->add("neili",-30);
			victim->receive_damage("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			return CYN "$n被$N发出的剑气刺中"RED+name+CYN"，真气不由得一滞！\n" NOR;
		}
	}

}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j, neili;
	int level,damage2;

	level= (int) me->query_skill("kumu-shengong",1);
	neili = me->query("neili");
	damage2= (int) ob->query("neili",1)/10;
	
	if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "kumu-shengong")
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		if (damage2 < 0 ) damage2=0;
		if (me->query("qi") <= me->query("max_qi"))
		{
			me->add("qi",damage2);
		}

		if (me->query("eff_qi") <= me->query("max_qi"))
		{
			me->add("eff_qi",damage2);
		}

		msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
		if (!ob->is_busy() && random(5)==0)
		{
			msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
			ob->apply_condition("yyz_damage",30);
			ob->start_busy(3);
		}

		message_vision(msg, me, ob);
		return j;
	}
}

