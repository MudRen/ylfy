// jiuyang-shengong.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({
([      "action" : "$N攻势忽缓而不疏，$w变化无常，捉摸不定向$n慢慢卷去",
        "force" : 330,
        "attack": 140,
        "dodge" : 35,
        "parry" : 85,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w突焕气象森严，便似千军万马奔驰而来，$w幻作一道红芒贯向$n",
        "force" : 310,
        "attack": 120,
        "dodge" : 25,
        "parry" : 25,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N卷起手中的$w，霎时剑芒暴涨，宛如骄阳烈火直射向$n而去",
        "force" : 340,
        "attack": 115,
        "dodge" : 20,
        "parry" : 25,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N运用$w幻化做一个一个圆圈，顿时无数火圈将$n团团包围",
        "force" : 285,
        "attack": 110,
        "dodge" : 25,
        "parry" : 25,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N回转$w遥指$n，顿时$w顶端顿时透出一道吞吐不定的火光，电射而出",
        "force" : 330,
        "attack": 118,
        "dodge" : 10,
        "parry" : 20,
        "damage": 420,
        "damage_type": "刺伤"
]),
});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)

{
	string msg;
	int extra;
	object ob = victim->query_temp("armor/finger");
	extra = (int)me->query("jiali");
	if (extra > 300) extra = 300;
    if( damage_bonus < 100 ) return 0;
	if(me->query("couple") || me->query("make_loves"))
	{
		return 0;
	}
	else
		if (me->query_skill("jiuyang-shengong",1) < 500) return 0;				 
        if( random(me->query("max_neili")) > random(victim->query("max_neili")) && random(3)==0)
		{
			msg = HIR "$N的九阳神功摧毁了$n的真元！！！！\n" NOR;
			if(objectp(ob))
				{
				if(ob->query("id") == "tianmo ring")
					{
					damage_bonus = damage_bonus / 2;
					msg = HIR "$n的天魔戒削弱了$N九阳神功的伤害！！！！\n" NOR;
					}
				}
				victim->receive_wound("qi", damage_bonus);
				victim->receive_wound("jing", extra );
				victim->add("neili", -extra);
				return msg;
		}
			
}

int valid_enable(string usage)
{
        return  usage=="unarmed" || usage=="parry" || usage=="force";

}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyang-shengong", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");
    if ( me->query("gender") != "男性")
        return notify_fail("九阳神功需要阳刚之气，不适合你学。\n");
    if ((int)me->query_skill("force", 1) < 500)
        return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
	if(me->query("couple"))
		return notify_fail("你非童男之体，不能学习九阳神功。\n");
	if(me->query("make_loves"))
		return notify_fail("你非童男之体，不能学习九阳神功。\n");

    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
//            if (sname[i]=="hunyuan-yiqi") continue;	
        if (sname[i]=="yijing-force") continue;
        if (sname[i]=="jiuyang-shengong") continue;
//            if (sname[i]=="taiji-shengong") continue;	
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("九阳神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

int effective_level() { return 21; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({

        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「九阳无我」，轻描淡写的化解了$N的攻势。\n",
});

string query_parry_msg(object me,object weapon)
{
            return parry_msg[random(sizeof(parry_msg))];
}

string exert_function_file(string func)
{
        return __DIR__"jiuyang-shengong/" + func;
}
