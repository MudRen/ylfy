// zhenfeng-qiangfa ���ǹ��

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w����$n��$l",
        "damage" : 40,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ���������硹��$w��˸����������$n��$l",
        "damage" : 50,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ذ���������$w���´̳���ֱ��$n��ȥ",
        "damage" : 60,
        "lvl"    : 10,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ������ǹ����ֱ��$n�ĺ�",
        "damage" : 80,
        "lvl"    : 20,
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ������â���ɡ������ֱ��$n",
        "damage" : 100,
        "lvl"    : 50,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 20)
                return notify_fail("��ġ�����ķ�����򲻹����޷�ѧ�����ǹ������\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷��������ǹ������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������������������ǹ������\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("������������������ǹ������\n");
        me->receive_damage("qi", 30);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenfeng-qiangfa/" + action;
}
