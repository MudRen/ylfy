// yifeng-jian.c �Ʒ罣��

inherit SKILL;

mapping *action = (
{
([      "action":"$Nʹһʽ��������ơ�������$w����΢�񣬻ó�һ�����������$n��$l",
	"force" : 130,
	"dodge" : 110,
	"damage": 200,
	"lvl" : 0,
    "skill_name" : "�������",
    "damage_type":  "����"
	 ]),
([      "action":"$N�Ʋ���ǰ��ʹ�����껨�׷ɡ�������Χ�ƣ�$w��������$n��$l��ȥ",
	"force" : 140,
	"dodge" : 110,
	"damage": 250,
	"lvl" : 9,
    "skill_name" : "�껨�׷�",
    "damage_type":  "����"
	 ]),
([      "action":"$Nһʽ�������䡹������Ʈ�����ߣ��˷�����������$wңң����$n��$l",
	"force" : 160,
	"dodge" : 150,
	"damage" : 300,
	"lvl" : 18,
    "skill_name" : "������",
    "damage_type":  "����"
	 ]),
([      "action":"$N��������Ծ��һʽ���ϻ����衹�����⻯Ϊ��ɫ��Ʈ��$n��$l",
	"force" : 180,
	"dodge" : 190,
	"damage": 350,
	"lvl" : 27,
    "skill_name" : "�ϻ�����",
    "damage_type":  "����"
	 ]),
([      "action":"$N����$w�й�ֱ����һʽ��������л����������Ϣ�ض�׼$n��$l�̳�һ��",
	"force" : 200,
	"dodge" : 220,
	"damage": 400,
	"lvl" : 36,
    "skill_name" : "������л",
    "damage_type":  "����"
	 ]),
([      "action":"$N����$wбָ���죬��â���£�һʽ���ɻ���Ҷ������׼$n��$lбб����",
	"force" : 210,
	"dodge" : 250,
	"damage": 450,
	"lvl" : 44,
    "skill_name" : "�ɻ���Ҷ",
    "damage_type":  "����"
	 ]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ�����ش�ء�����$n��$l",
	"force" : 220,
	"dodge" : 300,
	"damage": 500,
	"lvl" : 52,
    "skill_name" : "���ش��",
    "damage_type":  "����"
	 ]),
([      "action":"������,ֻ�����굽������,ͻȻ�����������$n,$n��ʱ��Ѫֱ��",
	"force" : 280,
	"dodge" : 350,
	"damage": 900,
	"lvl" : 150,
    "skill_name" : "�Ʒ������Ʒ���",
    "damage_type":  "����"
	 ]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	if ( me->query("gender") != "Ů��")
		return notify_fail("�ഫ�Ʒ罣����Ů�����,����������ϰ!\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("mingyu-shengong", 1) < 120)
		return notify_fail("���ڤ���񹦻��̫ǳ��\n");
	if ((int)me->query_skill("yifeng-jian", 1) >= (int)me->query_skill("sword",1))
		return notify_fail("��Ļ�������.\n");
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
	level   = (int) me->query_skill("yifeng-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
	if ( me->query("gender") != "Ů��")
		return notify_fail("�ഫ�Ʒ罣����Ů�����,����������ϰ!\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("mingyu-shengong", 1) < 420)
		return notify_fail("���ڤ���񹦻��̫ǳ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������Ʒ罣����\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"yifeng-jian/" + action;
}

