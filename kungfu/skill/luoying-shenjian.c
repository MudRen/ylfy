// luoying-shenjian.c ��Ӣ��
// by victori
#include <ansi.h>
inherit SKILL;
mapping *action = ({
    ([  "name": "��Ӣ�ͷ�",
        "action": "$Nʹһ�С�"+RED+"��Ӣ�ͷ�"+NOR+"������������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l",
        "force": 100,
        "parry": 5,
        "damage": 40,
        "damage_type":  "����"
        ]),
    ([  "name": "�����һ�",
        "action": "$N�趯$w��һʽ��"+MAG+"�����һ�"+NOR+"����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l",
        "force": 140,
        "parry": -20,
        "damage": 50,
        "damage_type":  "����"
    ]),
    ([  "name": "��������",
        "action": "$N������$nһת������$w����һָ��һʽ��"+MAG+"��������"+NOR+"���ó����콣Ӱ����$n$l�����ӳ�����",
        "force": 180,
        "dodge": 10,
        "damage": 70,
        "damage_type":  "����"
        ]),
    ([  "name": "���Ƿɻ�",
        "action": "$N����ƮȻ�����ڰ��������һ������Ȼһʽ��"+RED+"���Ƿɻ�"+NOR+"������$w�������޵�������$n��$l",
        "force": 210,
        "dodge": -10,
        "damage": 120,
        "damage_type":  "����"
        ]),
    ([  "name": "������",
        "action": "$N�������࣬һʽ��"+RED+"ϸ���ɷ���"+NOR+"��ͷ�½��ϣ�һ�С�"+BLU+"������"+NOR+"������$w���һ����������$n��$l",
        "force": 240,
        "dodge": 10,
        "damage": 120,
        "damage_type":  "����"
    ]),
    ([  "name": "���컨��",
        "action": "$Nһ�����ʹ����"+HIC+"���컨��"+NOR+"��������$w�ó����컨�꣬Ѹ����������$n��$l",
        "force": 280,
        "dodge": 15,
        "damage": 140,
        "damage_type":  "����"
    ]),
    ([  "name": "�仨����",
        "action": "$N��̾һ��������$w����һ����һʱ��"+HIY+"�仨����"+NOR+"����$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
        "force": 320,
        "dodge": 0,
        "damage": 140,
        "damage_type":  "����"
    ]),
});
int valid_learn(object me)
{
        object ob;
    if( (int)me->query_skill("bibo-shengong",1) < 100)
        return notify_fail("��ı̲��񹦻�򻹲�����\n");
    if( (int)me->query("max_neili") < 100 )
        return notify_fail("���������������������Ӣ�񽣡�\n");
        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ���\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        object ob;
    if( (int)me->query("qi") < 30 || (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ��Ӣ�񽣡�\n");
        if (!objectp(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ϰ��������\n");
    me->receive_damage("qi", 30);
        me->add("force", -5);
    write("�㰴����ѧ����һ����Ӣ�񽣡�\n");
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"luoying-shenjian/" + action;
}
