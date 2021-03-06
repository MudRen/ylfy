#include <combat.h>
inherit SKILL;
mapping *action = ({
([  "action":"$N将手中$w握紧，暴喝一声，不顾$n的凌厉攻击，刺向$n的头顶",
    "force" : 380,
    "lvl" : 0,  
    "damage_type" : "刺伤"
     ]),
([  "action":"$N手中$w一抖将$n的攻势化去，紧跟着反身一剑刺向$n",
    "force" : 500,
    "lvl" : 200, 
    "damage_type" : "刺伤"
    ]),
([  "action":"$n使出最后杀着，怎知$N也使出了最后绝技手中$w向$n对刺过去",
    "force" : 680,
    "lvl" : 500,
      "damage_type":"刺伤",
  ]),
});
int valid_enable(string usage) { return usage == "sword"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
      if (me->query_skill("sword",1) <= me->query_skill("langzi-sword",1))
      return notify_fail("你的基础不够，无法领会更高深的技巧！\n");
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
    mapping a_action;
    int i, level;
    
    level   = (int) me->query_skill("langzi-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    if ((int)me->query_temp("langzi-sword")>0)
        return (["action": BOLD "一"+weapon->query("unit")+"$w"+BOLD+"射向$n"+BOLD+"的$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"刺伤",
                 "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                ]);
    return a_action;

}

int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 35 )
        return notify_fail("你的内力或气不够，没有办法练习浪子三招。\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("你装备的武器不对。\n");
    me->receive_damage("qi", 30);
    me->add("force", -20);
    me->add_temp("pratice_sword",1);
   if (me->query_temp("pratice_sword") > me->query_skill("langzi-sword",1)/20 ){
           if( (int)ob->query_amount()==1 ) {
                   ob->unequip();
                   tell_object(me, BOLD "\n你的" + ob->query("name") + "用完了！\n\n"+NOR);
           }
           ob->add_amount(-1);
           me->delete_temp("pratice_sword");
    }
   write("你按著所学练了一遍浪子三招。\n");
    return 1;
}

void do_interlink(object me, object victim)
{
	int skill, max_enemy, max_att, i, j;
    object *enemy, weapon;
    string skill_name;

	if ( !objectp(weapon=me->query_temp("weapon")) ) return;
	
	skill = me->query_skill("langzi-sword", 1);
	
	if ( skill >= 500 
		&& me->query("kar", 1) > 27 
		&& me->query_skill("damo-force", 1) >= 500 )    
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;

		max_att = skill/(80*max_enemy)+3;
		if(max_att*max_enemy>50) max_att=50/max_enemy;

		if ( me->query("neili") < max_att*(10+me->query("jiali")) ) return;

		me->set_temp("langzi-sword", 1);
        me->add_temp("lianzhao", max_att);
		
		message_vision(MAG+"$N心静如水，手中"+weapon->name()+"一挥，剑意不断招式连绵不绝，似永不终止，无涯无境。\n\n" NOR,me);
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			for ( j=0; j<max_att; j++ )
			{
				if ( !objectp(weapon=me->query_temp("weapon")) ) break;
				if ( !stringp(skill_name=weapon->query("skill_type")) 
					|| skill_name != "sword" )
					break;
				if ( (me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) 
					&& enemy[i]->query("eff_qi") > 0 )
				{
					if ( environment(me) == environment(enemy[i]) )
					{
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_REGULAR);
						if ( me->query("neili") >= 10*max_att ) me->add("neili", -10*max_att);
					}
				}
				else 
					break;
			}
		}
		me->delete_temp("langzi-sword");
		me->delete_temp("lianzhao");
	}
}

int is_interlink()
{
	return 1;
}