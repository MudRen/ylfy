// mei 4/5/96
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action":"$N�������أ�ʱ��ʱ���Ľ����е�$w����ǰ�ƶ���ͻȻһ�С�"+BLU+"�Է��ʵ�"+NOR+"����$n��ȥ",
        "force" : 80,
        "damage_type":  "����"
]),
([      "action":"$NԨͣ���Ű�������͵��������ɣ�һ�С�"+RED+"�ɺ羪��"+NOR+"������է�ְ���$n��ȥ",
        "force" : 90,
        "damage_type":  "����"
]),
([      "action":"$NͻȻ����һ���������$wһ�죬һ�С�"+HIW+"��ѩ������"+NOR+"������$n",
        "force" : 80,
        "damage_type":  "����"
]),
([      "action":"$Nб������������$w�������󺮹⣬һ�С�"+MAG+"�ƻ�����"+NOR+"������$n",
        "force" : 80,
        "damage_type":  "����"
]),
([      "action":"$N˫��һ�٣�һ�С�"+YEL+"������"+NOR+"��,���е�$w�Լ�����ٶ�����$n",
        "force" : 90,
        "damage_type":  "����"
]),
([      "action":"$N��$w�����������������ʹ�˲��ҿ������͵�һ�С�"+RED+"������"+NOR+"����$n��ȥ",
        "force" : 140,
        "damage_type":  "����"
]),
([      "action":"$N���е�$w��������һ��������෭������������һ�С�"+HIW+"��һ��"+NOR+"������$n",
        "force" : 80,
        "damage_type":  "����"
]),
([      "action":"$N����ָ�죬���������һ�С�"+RED+"����Ѫ"+NOR+"����ʮ���������$n",
        "force" : 140,
        "damage_type":  "����"
]),
([      "action":"$NͻȻһ�С�"+HIC+"���޻�"+NOR+"��,���е�$w����һ�����е�һ�����磬����$n",
        "force" : 60,
        "damage_type":  "����"
]),
([      "action":"$NһԽ�οգ���Х����������һ�С�"+YEL+"�������"+NOR+"��$w����һ����������$n",
        "force" : 200,
        "damage_type":  "����"
]),
([      "action":"$N��Ȼ����һ�䣬�Բ��������Ŀ���Χ����$n���͵�һ�С�"+RED+"ǧ������"+NOR+"������$n",
        "force" : 340,
        "damage_type":  "����"
]),
});

int valid_enable(string usage) 
{ 
    return (usage == "axe" || usage == "parry"); 
}
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    return notify_fail("��������ֻ��ͨ���ж�(study)�������ߡ�\n");
}

mapping query_action(object me, object weapon)
{
    mapping ran_action;
    int level = me->query_skill("leiting-axe",1);
        if (me->query_temp("sum_power"))
        return ([  "action": "$N���������ᵽ��ǰ����ɫ���ص�ʩ����"+RED+"��������"+NOR+"������$n��$l",
                    "damage": level*6,
                    "attack": level*2,
                    "dodge": 0 - 5 * level,
                    "damage_type": "����",
                ]);
    else{
        ran_action=action[random(sizeof(action))];
        ran_action["dodge"]= 0 - level;
        ran_action["damage"]= level;
        ran_action["attack"]= level/2;
        }
    return ran_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "axe")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�����������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"leiting-axe/" + action;
}
