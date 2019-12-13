// jiuyang-shengong.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({
([      "action" : "$N���ƺ��������裬$w�仯�޳���׽��������$n������ȥ",
        "force" : 330,
        "attack": 140,
        "dodge" : 35,
        "parry" : 85,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$N���е�$wͻ������ɭ�ϣ�����ǧ�������۶�����$w����һ����â����$n",
        "force" : 310,
        "attack": 120,
        "dodge" : 25,
        "parry" : 25,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w����ʱ��â���ǣ����罾���һ�ֱ����$n��ȥ",
        "force" : 340,
        "attack": 115,
        "dodge" : 20,
        "parry" : 25,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N����$w�û���һ��һ��ԲȦ����ʱ������Ȧ��$n���Ű�Χ",
        "force" : 285,
        "attack": 110,
        "dodge" : 25,
        "parry" : 25,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N��ת$wңָ$n����ʱ$w���˶�ʱ͸��һ�����²����Ļ�⣬�������",
        "force" : 330,
        "attack": 118,
        "dodge" : 10,
        "parry" : 20,
        "damage": 420,
        "damage_type": "����"
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
			msg = HIR "$N�ľ����񹦴ݻ���$n����Ԫ��������\n" NOR;
			if(objectp(ob))
				{
				if(ob->query("id") == "tianmo ring")
					{
					damage_bonus = damage_bonus / 2;
					msg = HIR "$n����ħ��������$N�����񹦵��˺���������\n" NOR;
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
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
    if ( me->query("gender") != "����")
        return notify_fail("��������Ҫ����֮�������ʺ���ѧ��\n");
    if ((int)me->query_skill("force", 1) < 500)
        return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	if(me->query("couple"))
		return notify_fail("���ͯ��֮�壬����ѧϰ�����񹦡�\n");
	if(me->query("make_loves"))
		return notify_fail("���ͯ��֮�壬����ѧϰ�����񹦡�\n");

    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
//            if (sname[i]=="hunyuan-yiqi") continue;	
        if (sname[i]=="yijing-force") continue;
        if (sname[i]=="jiuyang-shengong") continue;
//            if (sname[i]=="taiji-shengong") continue;	
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

int effective_level() { return 21; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({

        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ�����������ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});

string query_parry_msg(object me,object weapon)
{
            return parry_msg[random(sizeof(parry_msg))];
}

string exert_function_file(string func)
{
        return __DIR__"jiuyang-shengong/" + func;
}
