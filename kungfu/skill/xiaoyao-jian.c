//
//xiaoyao-jian  ��ң����
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢����һ�С��������硹����$w����һ���׺磬ֱ����$n����ǰ",
        "skill_name" : "��������",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С����·ת���������������ģ���Ȼһ��ֱ����$w�ɴ�$n",
        "skill_name" : "���·ת",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N����$w�������佣����һ�С��׷����������$nȫ��",
        "skill_name" : "�������",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N�Ų����ƣ�����Ʈ����һ�С��紵�仨����$wͬ�Ǵ���$n�ĸ���Ҫ��",
        "skill_name" : "�����Ϸ�",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 50,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N���α�ã�����һ����һ�С��ؿ����ơ�������$n��ǰ",
        "skill_name" : "�ؿ�����",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�Ц�����硹���������赭д��ȴ��������$nȫ��ҪѨ",
        "skill_name" : "Ц������",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 100,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ���¹����ء���$w���һ�����⣬������ã�Ž���������$n",
        "skill_name" : "�¹�����",
        "force" : 300,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 130,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N������$w,һ�С�������Ϣ����$wȴ�Լ������ٶ�ֱֱ��$n��ȥ   ",
        "skill_name" : "������Ϣ",
        "force" : 500,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 150,
        "damage" : 100,
        "damage_type" : "����",
]),


});


int valid_enable(string usage) { return usage == "sword" ; }


int valid_learn(object me)
{
	if ((int)me->query_skill("blade", 1) >= 30)
		return 1;
	else if ((int)me->query_skill("sword", 1) < 30)
		return notify_fail("��Ļ�������̫���ˣ���������ң������\n");
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
	level   = (int) me->query_skill("xiaoyao-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 20)
		return notify_fail("���������������������ң������\n");
	me->receive_damage("qi", 30);
	return 1;
}

