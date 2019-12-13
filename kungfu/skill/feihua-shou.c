// feihua-shou.c -�ɻ�ժҶ��
inherit SKILL;
mapping *action = ({
([      "action" : "$Nһ�С���ͷ���¡�š����������һ�һ���Ӧ�����������������������$N��",
        "force" : 40,
        "dodge" : 5,
        "damage": 15,
        "lvl" : 0,
//        "weapon":"��",
        "skill_name" : "��ͷ����",
        "damage_type" : "����"
]),
([      "action" : "$N���п��ϼ���𻨣��á�������꡹���ַ�ɢ������������$n��ȫ�����ҪѨ��",
        "force" : 50,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 8,
//        "weapon":"��",
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��˫������$n�յУ�һʽ�����ɳ²֡������һ�У����ſ��У����ޣ�����һ���³�һ�������$n��",
        "force" : 60,
        "dodge" : 15,
        "damage": 20,
        "lvl" : 60,
//      "weapon":"��",
        "skill_name" : "���ɳ²�",
        "damage_type" : "����"
]),
([      "action" : "$N���ֵ���һ��𻨣�Ϯ��$n,������������ʱ��һ�С����»�ӳ��,���ֵ������һ�������ǰ�ߣ����ǰ��Ľ�����������Ѹ�����׵�����$n����$n���һ����",
        "force" : 100,
        "dodge" : 20,
        "damage": 30,
        "lvl" : 100,
//        "weapon":"��",
        "skill_name" : "���»�ӳ",
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingzhua-gong"; }
int valid_learn(object me)
{
      
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻�򲻹����޷�ѧ��Ҷժ���֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ҷժ���֡�\n");
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
        int i, level;
        level   = (int) me->query_skill("feihua-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������Ҷժ���֡�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}
string *parry_msg = ({
        "ֻ�������ϡ�һ������$p���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n������$v�ܿ���\n",
        "����$n����һ�࣬������$v�񿪡�\n",
});
string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"feihua-shou/" + action;
}        