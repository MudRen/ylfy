// dragon.c ��֮����
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "����$nһ�����$N���ס�ˣ����ҷ��ֽ�����\n",
        "����$n����һ����$N��һ�����˸��ա�\n",
        "$n�ڿ�Ծ�𣬶㿪��$N����һ�С�\n",
        "$nҲ��������ֱ��$N��ȥ��$Nһ������ֻ�������˿���\n",
});

mapping *action = ({
([  "action":"$N����һ�࣬β�ͺ�Ȼ�����˦����ɨ��$n",
    "dodge" : 40,
    "damage": 600,
    "damage_type":  "����"
]),
([  "action":"$N��Ȼ�ӽ��������ҧ$n",
    "dodge" : 60,
    "damage": 300,
    "damage_type":  "����"
]),
([  "action":"$N��ץ�ŵأ���ץֱ��$n�沿",
    "dodge" : 50,
    "damage": 400,
    "damage_type":  "����"
]),
([  "action":"$NͻȻһԾ���ӿ���ֱ��$n",
    "dodge" : 100,
    "damage": 600,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ�㣬��ȫ��֮��ײ��$n",
    "dodge" : 40,
    "damage": 1000,
    "damage_type":  "����"
]),

});

int valid_enable(string usage) 
{ 
	return usage == "unarmed" ||  usage == "dodge" ||usage == "parry" ; 
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	return notify_fail("��֮�����޷�ͨ����ϰ���ɳ���\n");
}
int valid_learn(object me)
{
	 return 1; 
 }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"dragon/" + action;
}