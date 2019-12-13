// tiangang-zhi.c ���ָѨ��
// create by host dec,20
inherit SKILL;

mapping *action = ({
([  "action" : "$N��ָ���˸���Ȧ��һʽ��������ġ����¶��ϵ���$n�ĵ���",
    "force" : 150,
    "dodge" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([  "action" : "$N����ָ˫��һ�С�������̶��������$n���ء���ء���������Ѩ��",
    "force" : 200,
    "dodge" : 10,
    "damage": 20,
    "lvl" : 5,
    "skill_name" : "������̶",
    "damage_type" : "����"
]),
([  "action" : "$N���������У�һʽ�����߾��ɡ�����ָ����������ָ��$n��$l",
    "force" : 250,
    "dodge" : 15,
    "damage": 25,
    "lvl" : 10,
    "skill_name" : "ǧ����ָ",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��������ɽ����������ʽ����ָ�ó�һ��ָ�磬���ص���$n��$l",
    "force" : 300,
    "dodge" : -5,
    "damage": 30,
    "lvl" : 20,
    "skill_name" : "������ɽ",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ����������������ָ��Σ���ָ��۵糸�㼱������$n��$l",
    "force" : 240,
    "dodge" : 15,
    "damage": 35,
    "lvl" : 30,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ���ض�ɽҡ�����ȫ��������˫ָ�ų�һ�����ˣ�����$n",
    "force" : 280,
    "dodge" : -20,
    "damage": 40,
    "lvl" : 40,
    "skill_name" : "�ض�ɽҡ",
    "damage_type" : "����"
]),
([  "action" : "$N�������һʽ��ˮ�����¡������ֻ���һȦ������$n��$l",
    "force" : 320,
    "dodge" : 20,
    "damage": 45,
    "lvl" : 60,
    "skill_name" : "ˮ������",
    "damage_type" : "����"
]),
([  "action" : "$N���������һʽ��̩ɽѹ������˫�ֻó�����ָ�磬���϶�����$n",
    "force" : 380,
    "dodge" : 5,
    "damage": 50,
    "lvl" : 80,
    "skill_name" : "̩ɽѹ��",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("ѧϰ�����ָѨ����������֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
            return notify_fail("��ġ��ټ�ʮ��ׯ����򲻹����޷�ѧϰ�����ָѨ������\n");
	if ((int)me->query("max_neili") < 100)
            return notify_fail("�������̫�����޷�ѧϰ�����ָѨ������\n");
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
    level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ( !me->query_skill("linji-zhuang",1) )
           return notify_fail("�������ָѨ��������Ҫ�С��ټ�ʮ��ׯ�������ӡ�\n");

	if ((int)me->query("qi") < 30)
           return notify_fail("���������������Ϣһ�������ɡ�\n");

	if ((int)me->query("neili") < 20)
           return notify_fail("�����������������ָ��ͨ����\n");

        me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhi/" + action;
}