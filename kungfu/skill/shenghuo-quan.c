// shenghuo-quan.c ʥ��ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С���˳�������˫�����·��ɣ�����$n��$l",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "��˳���",
        "damage_type" : "����"
]),
([      "action" : "$N���ֻ�ס��ǰ������ʹһ�С�������Х������$n��$l��ȥ",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "������Х",
        "damage_type" : "����"
]),
([      "action" : "$NĬ��������ȫ��������죬һ�С��������衹����$n��$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N������ͬʱʹ�����������衹,����һ����������$n��$l",
        "force" : 500,
        "dodge" : 5,
        "skill_name" : "˫����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ʥ��ȭ������֡�\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 20)
                return notify_fail("���ʥ���񹦻�򲻹����޷�ѧʥ��ȭ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷���ʥ��ȭ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������ʥ��ȭ��\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}