inherit SKILL;

mapping *action = ({
([	"action" : "$N˫�ƽ���,һ�С����项��������̽�����ƾ�������$n��ͷ��",
	"force" : 130,
	"dodge" : 20,
	"damage" : 60,
	"lvl" : 0,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([	"action" : "$N���������һ�С����⡹���Ʒ���ϸ�����$n��$lɨȥ",
	"force" : 150,
	"dodge" : 10,
	"damage" : 80,
	"lvl" : 20,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����᡹��˫�ƻû�ΪһƬ��Ӱ����$n�����ڻ�Ӱ֮�ڡ�",
	"force" : 150,
	"dodge" : 30,
	"damage" : 95,
	"lvl" : 30,
	"skill_name" : "����",
	"damage_type" : "����"
]),

([	"action" : "$N������շ���һ�С��޺ۡ�����$n��$l��������",
	"force" : 200,
	"dodge" : 25,
	"damage" : 180,
	"lvl" : 40,
	"skill_name" : "�޺�",
    "damage_type" : "����"
]),
([	"action" : "$N�������ᣬһ�С���������ֻ��˫�ƹ�������бб����$n",
	"force" : 250,
	"dodge" : 20,
	"damage" : 200,
	"lvl" : 40,
	"skill_name" : "����",
	"damage_type" : "����"
]),

([	"action" : "ֻ��$N�������ʹ��һ�С�����������$n,$n��æ�мܣ�ȴ��$N˫��һ��/n
Ϊ֮���ʵ�˾����Ƶ���߾���,һ�С����ݡ���������$n������",
	"force" : 300,
	"dodge" : 25,
	"damage" : 250,
	"lvl" : 60,
	"skill_name" : "����",
            "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ||usage=="unarmed" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("mingyu-shengong", 1) < 120)
		return notify_fail("���ڤ���񹦻�򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	level   = (int) me->query_skill("jueqing-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueqing-zhang/" + action;
}