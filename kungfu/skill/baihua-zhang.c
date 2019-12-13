//���ٻ��ơ�baihua-zhang.c
inherit SKILL;

mapping *action = ({
        ([      "action":               "$NǳǳһЦ��һ�С����ڷɻ������Ρ��������޵�����$n��$l",
                "damage":150,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N����һ�٣��������⡣$n����������\n����$N������ָ��ֱ��$n˫Ŀ�����ǡ��ٻ��ơ�֮ɱ�֡�һ֦���ӳ�ǽ����",
                "damage":190,
                "damage_type":  "����",
                        "weapon":               "������",
        ]),
        ([      "action":               "ֻ��$N��ȻһЦ��˫�Ʒ��ɣ�һ�С������һ���ӳ�졹�����������",
                "damage":230,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N����һ�ڣ���Ȼ�������ߣ�����˳��һ�С��ƾ�֦ͷ����������$n��$l��ȥ",
                "damage":260,
                "damage_type":  "����",
        ]),
            ([  "action":               "ֻ��$N˫�����գ���ɫ���أ�һ�С��˻��������޻���ȫ������$n��$l",
                "damage":400,
                "damage_type":  "����",
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�ٻ�����ֻ��Ů�Ӳ��������书��\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("���ٻ��Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 30)
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("qi") < 30 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 40 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 30);
        me->add("neili", -10);

        return 1;
}
