//guxing-sword.c ���ǽ���

inherit SKILL;
mapping *action = ({
([  "action" : "$N�鲽������һ�С�"+HIM+"���ǰ���"+NOR+"��������$w���������һ��������$n��$l",
    "force" : 400,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��"+YEL+"�ǹ�˲��"+NOR+"��ֱ��$n��$l",
    "force" : 370,
    "lvl" : 10,
    "damage_type" : "����"
]),
([  "action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ��"+WHT+"���Ǹ���"+NOR+"������$n��$l",
    "force" : 380,
    "lvl" : 15,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"��ɲ����"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 330,
    "lvl" : 37,
    "damage_type" : "����"
]),
([  "action" : "$N���������һš��һ�С�"+BLK+"������β"+NOR+"��������$w������$n��$l��ȥ",
    "force" : 410,
    "lvl" : 48,
    "damage_type" : "����"
]),
([  "action" : "$N������ϥ������$wбָ��һ�С�"+HIC+"��ɽԽ��"+NOR+"������$n��$l",
    "force" : 430,
    "lvl" : 60,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+CYN+"ܽ�س�ˮ"+NOR+"����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
    "force" : 140,
    "lvl" : 70,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int practice_level(){   return 145;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧ���ǽ�����\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("guxing-sword", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("guxing-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*3;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������ǽ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"guxing-sword/" + action;
}
