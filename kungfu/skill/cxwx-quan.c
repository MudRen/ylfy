// marry 99.8
inherit SKILL;
#include <ansi.h>
mapping *action = ({
    ([  "action":       "$Nʹһ�С�"HIM"����һƬ"NOR"����˫ȭƮ�Ʋ�������$n$l",
        "dodge": 10,
        "parry": -10,
        "force": 50,
        "damage_type": "����"
        ]),
    ([  "action":       "$Nٿ������$n��ǰ��һ�С�"HIB"����ɿ�"NOR"��ֱ��$n��$l",
        "dodge": 20,
        "parry": -10,
        "force": 100,
        "damage_type": "����"
    ]),
    ([  "action":       "$N������$nһת��һ�С�"HIY"��Ԩ����"NOR"����$n$l������ȭ",
        "dodge": 30,
        "parry": -10,
        "force": 200,
        "damage_type": "����"
        ]),
    ([  "action":       "$N���ΰ����ڰ��һ�С�"MAG"����֮��"NOR"�������ͻ�$n��$l",
        "dodge": -10,
        "parry": -10,
        "force": 350,
        "damage_type": "����"
        ]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����������ȭ������֡�\n");
        if ((int)me->query("max_neili") < 1000)
        return notify_fail("�������̫�����޷�����������ȭ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"cxwx-quan/" + action;
}
