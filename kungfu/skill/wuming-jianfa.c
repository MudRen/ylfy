// 无名剑法	

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"\n$N默念 ≈幽≈,剑气纵横直直指向$n的$l"NOR, 
	"force" : 160,
	"lvl" : 0,
"skill_name" : "★幽★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIR"\n$N默念 ≈恨≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 240,
	"lvl" : 50,
"skill_name" : "★恨★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIY"\n$N默念 ≈怨≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 280,
	"lvl" : 75,
"skill_name" : "★怨★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIM"\n$N默念 ≈爱≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 320,
	"lvl" : 120,
"skill_name" : "★爱★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIC"\n$N默念 ≈思≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 380,
	"lvl" : 230,
"skill_name" : "★思★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIG"\n$N默念 ≈情≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 420,
	"lvl" : 250,
"skill_name" : "★情★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":CYN"\n$N默念 ≈恩≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 450,
	"lvl" : 330,
"skill_name" : "★恩★字诀",	
	"damage_type":	"刺伤"
]),
([      "action":HIR"\n$N默念 ≈仇≈,剑气纵横直直指向$n的$l"NOR,               	
	"force" : 480,
	"lvl" : 380,
"skill_name" : "★仇★字诀",	
	"damage_type":	"内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
        return notify_fail("无名剑法没法教授。\n");	
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
level   = (int) me->query_skill("wuming-jianfa",1);	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}


int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
    if((int)me->query_skill("wuming-jianfa",1) < 300)	
        return notify_fail("你试着练习无名剑法,但是没有任何进步。\n");	
	if ((int)me->query("qi") < 40)
        return notify_fail("你的体力不够练无名剑法。\n");	
	me->receive_damage("qi", 20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random( me->query_skill("sword") ) > random( victim->query_skill("force")) && random(2)==0) {
		victim->receive_wound("qi", damage_bonus/ 3 );
		return HIR "你听到「哧」一声轻响一道霸气扑天而来，忽然间$n血冒三丈，被$N剑气所伤！\n"NOR;
	}
   }
string perform_action_file(string action)
{
return __DIR__"wuming-jianfa/" + action;	
}
