// zhenfeng-jianfa ��罣��

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w����$n��$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 10,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��[1;30m�������硹[0m��$w��˸����������$n��$l",
        "force" : 55,
        "dodge" : 30,
        "damage" : 20,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��[1;34m�����ذ���[0m������$w���´̳���ֱ��$n��ȥ",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 10,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ��[1;33m���������[0mֱ��$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
        "damage" : 40,
        "lvl"    : 20,
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ��[5;1;31m�[5m�[5m�[5m�[5m�[5m�[5m�[5m�[5m�[5m�[5m�[5m�[0m�����ֱ��$n",
        "force" : 140,
        "dodge" : 70,
        "damage" : 60,
        "lvl"    : 60,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 20)
                return notify_fail("��ġ�����ķ�����򲻹����޷�ѧ����罣������\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�������罣������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������罣������\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("�����������������罣������\n");
        me->receive_damage("qi", 30);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenfeng-jianfa/" + action;
}
