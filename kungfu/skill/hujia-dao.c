//hujia-dao  胡家刀法

#include <combat.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N轻提刀尖,使出一招「说一不二」，$w直砍向$n的手臂",
        "skill_name" : "说一不二",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "劈伤",
]),
([      "action" : "$N反转刀尖，一招「倒转乾坤」，手中$w竟然用刀背劈向$n的胸前",
        "skill_name" : "倒转乾坤",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "劈伤",
]),
([      "action" : "$N一提气，劲贯刀锋，$w“嗡嗡”做响，一招「气贯山河」，自上而下直插$n的头顶",
        "skill_name" : "气贯山河",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "割伤",
]),
([      "action" : "$N足尖一点，人随刀势，刀借人力，一招「云外飞天」，$w从半空中劈向$n",
        "skill_name" : "云外飞天",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 45,
        "damage" : 50,
        "damage_type" : "劈伤",
]),
([      "action" : "$N一声长啸，刀竟脱手而出，乘$n不备，飞身而上，半空中一抄刀，\n斩向$n的腰部，竟然是一招「灵狐出洞」",
        "skill_name" : "灵狐出洞",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 60,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「乱批风雪」，一柄刀使得密不透气，连斩七七四十九刀，攻向$n周身要害",
        "skill_name" : "乱批风雪",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使一式「千山重峦」，刀势一波接一波，连绵不断的直朝$n压去  ",
        "skill_name" : "千山重峦",
        "force" : 340,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 80,
        "damage" : 80,
        "damage_type" : "割伤",
]),

});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }	

int valid_learn(object me)
{
	if ( (int)me->query_skill("blade", 1) < 500 )        	
		return notify_fail("你的基本刀法太差了，练不了胡家刀法。\n");
	if ( me->query_skill("blade", 1) <= me->query_skill("hujia-dao", 1) )
		return notify_fail("你的基础太差了，无法领会胡家刀更深的奥意。\n");
	if ( (int)me->query_skill("hujia-dao",1) >= 900 )
		return notify_fail("师傅只能教你到这，以后要靠自己多加练习体会。\n");
	if ( me->query_skill("hujia-dao", 1) < 100 )
		return notify_fail("你的胡家刀法基础太差了，还是先在书本上多下下功夫吧。\n");

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
	if (random(me->query_skill("blade")) > 80 &&
	    me->query_skill("force") > 100 &&
	    me->query("neili") > 500 &&
        weapon->query("id") == "chuangwang baodao" ) {	
		me->add("neili", -100);
		return ([
		"action": "$N使出一招「大雪纷纷」，$w发出万长白芒，寒光四射，直劈向$n",
		"damage": 400,
		"force" : 200,
		"damage_type": "割伤"]);
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了胡家刀法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action){    return __DIR__"hujia-dao/" + action;}	

void do_interlink(object me, object victim)
{
	int skill, max_enemy, max_att, i, j;
    object *enemy, weapon;
    string all_enemy, skill_name;

	if ( !objectp(weapon=me->query_temp("weapon")) ) return;
	
	skill = me->query_skill("hujia-dao", 1);
	
	if ( skill > 500 
		&& me->query("str") > 30 )
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;

		all_enemy = "";
		max_att = skill/(60*max_enemy);
		if(max_att*max_enemy>50) max_att=50/max_enemy;

		if ( me->query("neili") < max_att*(50+me->query("jiali")) ) return;
        
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			all_enemy += enemy[i]->name();
			if ( i < max_enemy-1) all_enemy += "、";
		}
        
		message_vision(HIC+"$N眼中寒光一闪，使出胡家刀法绝技「"+HIW+"漫天飞雪"+HIC+"」，一道道刀气如雪卷向"+all_enemy+"。\n\n" NOR,me);
		me->set_temp("hujia-dao", 1);
        me->add_temp("lianzhao", max_att);
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			for ( j=0; j<max_att; j++ )
			{
				if ( !objectp(weapon=me->query_temp("weapon")) ) break;
				if ( !stringp(skill_name=weapon->query("skill_type")) 
					|| skill_name != "blade" )
					break;
				if ( (me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) 
					&& enemy[i]->query("eff_qi") > 0 )
				{
					if ( environment(me) == environment(enemy[i]) )
					{
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_QUICK);
						if ( me->query("neili") >= 50*max_att ) me->add("neili", -50*max_att);
					}
				}
				else 
					break;
			}
		}

		me->delete_temp("hujia-dao");
		me->delete_temp("lianzhao");
	}
}

int is_interlink()
{
	return 1;
}