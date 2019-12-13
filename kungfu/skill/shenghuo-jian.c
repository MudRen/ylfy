// shenghuo-jian.c ʥ�𽣷�

inherit SKILL;

mapping *action = ({
([      "action" : "$N�ٽ����죬һ�С�ʥ����ġ�������$w���������������һ������$n��$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N�ὣ��ת����������������$wʹ��һʽ��ʥ�����졹ֱ��$n��$l",
        "force" : 180,
        "dodge" : 15,
        "damage" : 40,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ʥ�𡹣�$w���϶��»���һ�����⣬ƽƽ����$n��$l��ȥ",
        "force" : 200,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ʥ�𡹣�$N��$w����һ��������ɨ$n��$l",
        "force" : 250,
        "dodge" : 10,
        "damage" : 80,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��Ȼʥ�𡹣�$w����س飬�ý���ĥ��$n��$l",
        "force" : 350,
        "dodge" : 5,
        "damage" : 90,
        "lvl" : 59,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ʥ���Ȼ����������ָ���Խ��ⷢ��һ�����������$n��$l",
        "force" : 400,
        "dodge" : -5,
        "damage" : 100,
        "lvl" : 79,
        "damage_type" : "����"
]),
([  "action" : "$N˫�ֺ�ʮ��һ�С�����߷١����þ�������$w����һ�Ž���������$n��$l",
        "force" : 600,
        "dodge" : -5,
        "damage" : 180,
        "lvl" : 99,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level   = (int) me->query_skill("shenghuo-jian",1);
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
        if ((int)me->query("qi") < 60)
                return notify_fail("�������������ʥ�𽣷���\n");
        me->receive_damage("qi", 40);
        return 1;
}

