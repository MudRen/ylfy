// qishenu-dao.c ���񵶷�
inherit SKILL;
mapping *action = ({
([      "action" : "$N����$wбָ��һ�С���Ŀȫ�ǡ����������ŵ��棬��$n��$l��ȥ",
        "force" : 120,
        "dodge" : -10,
        "parry" : 5,
        "damage" : 115,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������������$w�����ַ��գ�����Ӷ������˾�ɼ�׶��������$nֱ�����",
        "force" : 130,
        "dodge" : -10,
        "parry" : 10,
        "damage" : 120,
        "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С�Ѫ����𡹣�����һ������ն��$n",
        "force" : 140,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 130,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������롹��$w�󿪴��أ����϶��»���һ�����磬ֱ����$n",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С��з�֮ʹ����˫�ֳ����������У�����$n���ؿ�",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 150,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����زҡ�������������裬�˵�������ƣ���������$n",
        "force" : 210,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������š������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 170,
        "damage_type" : "����"
]),
([      "action" : "$N����פ�أ�һ�С��������񡹣��ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 280,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 180,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
if ((int)me->query_skill("blade", 1) < 1000)
                return notify_fail("��Ļ����������̫ǳ��\n");
if ((int)me->query_skill("qishen-dao", 1) > 300)    
return notify_fail("�ý̵Ķ��̸�����,�Ժ��Լ���������ϰ�ɡ�\n");    
        return 1;
}
mapping query_action(object me, object weapon)
{
int zhaoshu, level;
zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("qishen-dao",1);
if (level < 60 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("����������������񵶡�\n");
        me->receive_damage("qi", 40);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"qishen-dao/" + action;
}
