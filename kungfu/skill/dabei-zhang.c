inherit SKILL;
mapping *action = ({
([  "action" : "$N�����ϲ���һʽ��"+YEL+"��ȴ�"+NOR+"���������ַֿ�����ȭΪ�ƣ�����$n��$l",
    "force" : 380,
    "lvl" : 0,
    "skill_name" : YEL "��ȴ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�����̤��ȫ����ת��һ�С�"+RED+"��������"+NOR+"���������͵ز���$n��$l",
    "force" : 300,
    "lvl" : 8,
    "skill_name" : RED "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С�"+HIB+"�ຣ��ͷ"+NOR+"��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
    "force" : 300,
    "lvl" : 33,
    "skill_name" : HIB "�ຣ��ͷ" NOR ,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ƻ�����һ�ǡ�"+HIY+"��ͷ�ǰ�"+NOR+"�����Ƴ���磬һ�����е�$n������",
    "force" : 360,
    "lvl" : 42,
    "skill_name" : GRN "��ͷ�ǰ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+WHT+"�ຣ�ޱ�"+NOR+"����˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
    "force" : 420,
    "lvl" : 50,
    "skill_name" : WHT "�ຣ�ޱ�" NOR,
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike";}
int practice_level(){   return 58;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("ѧ���Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������̫�����޷������ơ�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("dabei-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	if (me->query_skill("damo-force", 1) <= me->query_skill("dabei-zhang", 1))
        return notify_fail("��Ĵ�Ħ��̫�ͣ��޷����и�����Ĵ��ơ�\n");
       return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("dabei-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("����������������ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dabei-zhang/" + action;
}
