//by yushu 2001.2
/*
�ɺ׽���    dodge  -5    parry  -5    damage  25
��ɽ����ɽ����������ʽ��
*/

//����ӭ�͡��ƹȺ׷塡��ɽ������
//�׺�����Я�����ơ���������
inherit SKILL;
#include <ansi.h>
mapping *action = (
{
([      "name":                 "����ӭ��",
"action":"$N��������,����$w���գ���$n��ȥ�������ƿ�ɽ��һ�㣬��һ�����ۺ��"HIC"������ӭ�͡�"NOR"",
"dodge":  -10,
	"parry":   20,
	"lvl" :    30,
	"force" : 100,
	"damage": 300,
"damage_type": "����"
	 ]),
([      "name":                 "�ƹȺ׷�",
"action":"ֻ��$N���ָ�����������轣������$w��$n��ȫ��ȥ\n""����һ��"HIR"���ƹȺ׷塹"NOR"��",
	"dodge":    24,
"parry":   -19,
	"lvl" :    40,
	"force" :  200,
	"damage":  320,
"damage_type":  "����"
	 ]),
([      "name":                 "��ɽ����",
"action":"$N������ǰ������$w���裬һ��"HIM"����ɽ������"NOR"�ó����Ž�â����$n������������",
"dodge": -15,
"parry": -15,
	"lvl" : 40,
	"force" : 300,
	"damage": 340,
"damage_type": "����"
	 ]),
([      "name":                 "�׺�����",
"action":"$N���˷��������һ����Х������$w������$n��$l��ȥ������ɽ����Х���"HIG"���׺�����"NOR"��ȫ��$n������",
	"dodge":  15,
	"lvl" :  40,
	"force":  400,
	"damage": 360,
"damage_type": "����"
	 ]),
([      "name":                 "Я������",
"action":"ֻ��$N������أ�ʹ��һ��"HIW"��Я�����ơ�"NOR"������$w���ٷɽ���������㽣����ֱ��$n��$l��ȥ",
"dodge":-10,
"parry":  -50,
	"lvl" : 40,
	"force" : 140,
	"damage": 500,
"damage_type": "����"
	 ]),
([      "name":                 "��������",
"action":"$N����ǰ����һʽ"HIB"���������硹"NOR"�����潣����$nȫ���������â������������������$n�������ܵù�",
"dodge":   -15,
"parry":   -100,
	"lvl" :     50,
	"force" :  150,
	"damage":  600,
"damage_type": "����"
	 ])
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("���������Ϊ������޷�ѧϰ�ɺ׽�����\n");
	if (!(ob = me->query_temp("weapon"))
	        || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���ɺ׽����к����档\n");
	if ((int)me->query("neili") < 5)
		return notify_fail("���������㣬ǿ���ɺ׽������߻���ħ��Σ�ա�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	message_vision("$NĬĬ������һ�����Ȼ������һ���ɺ׽�����\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
	return __DIR__"songhe-sword/" + func;
}
�