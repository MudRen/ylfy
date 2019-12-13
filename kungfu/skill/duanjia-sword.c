// duanjia-sword.c �μҽ�

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�������˸�����������$wƽƽ�ݳ���һʽ"+(order[random(13)])+"�������Ͻ�"NOR"ֱ��$n��ǰ��",
        "force" : 150,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��$w��һ���벻���ĽǶ�ͻȻ������һʽ"+(order[random(13)])+"���̼�������"NOR"ֱ��$n������",
        "force" : 180,
        "dodge" : 15,
        "damage" : 85,
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"�������ڿա�"NOR"������Ծ�ڰ�գ�$w��������?��ֱ��$n��ͷ��",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����б�ӣ�����ָ��$n�ĸ�����һ��"+(order[random(13)])+"����Ԩ���ԡ�"NOR"�����¶��ϣ�����$n",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�б�ɶ�����$w����$n��$l,��һ��"+(order[random(13)])+"��Цָ���ϡ�"NOR"",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ�����ὣ�������͸������֮�⣬���ǶμҲ���֮��"+(order[random(13)])+"����¹��ԭ��"NOR"��������ס$n��ȫ��",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 65,
        "damage_type" : "����"

]),
([  "action" : "$N��ǰ����һ����һ��"+(order[random(13)])+"���ƺ����롹"NOR"������$w����������$n��$l������ȥ",
    "force" : 150,
    "dodge" : 130,
    "damage" : 25,
    "lvl" : 0,
    "skill_name" : "�ƺ�����",
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ"+(order[random(13)])+"������ֱ�¡�"NOR"ֱ��$n��$l",
    "force" : 200,
    "dodge" : 115,
    "damage" : 40,
    "lvl" : 9,
    "skill_name" : "����ֱ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"��ѩӿ���ء�"NOR"��$w�����������⣬���¶��Ϸ���$n��$l",
    "force" : 220,
    "dodge" : 115,
    "damage" : 65,
    "lvl" : 19,
    "skill_name" : "ѩӿ����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"�����ͻ��"NOR"������$w���ƺ�ɨʵ��б��������$n��$l",
    "force" : 250,
    "dodge" : 110,
    "damage" : 85,
    "lvl" : 29,
    "skill_name" : "���ͻ��",
    "damage_type" : "����"
]),
([  "action" : "$Nʹ��"+(order[random(13)])+"��ҹ��̽����"NOR"��$w����������������಻�ϻ���$n��$l",
    "force" : 280,
    "dodge" : 115,
    "damage" : 100,
    "lvl" : 39,
    "skill_name" : "ҹ��̽��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"��̩ɽѹ����"NOR"������һ�󽣾�������$w���϶������������ֱ��$n��$l������ȥ",
    "force" : 300,
    "dodge" : 115,
    "damage" : 120,
    "lvl" : 89,
    "skill_name" : "̩ɽѹ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"������滨��"NOR"�����ڰ�գ�$w�س飬���ֹ���$n��$l",
    "force" : 350,
    "dodge" : 110,
    "damage" : 140,
    "lvl" : 99,
    "skill_name" : "����滨",
    "damage_type" : "����"
]),
([  "action" : "$N��Ӱһ��, �Ƶ�$n����һ��"+(order[random(13)])+"����¹��ԭ��"NOR"��������$n��$l����",
    "force" : 400,
    "dodge" : 115,
    "damage" : 250,
    "lvl" : 100,
    "skill_name" : "��¹��ԭ",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("�������������\n");
if ((int)me->query_skill("kumu-shengong", 1) < 500)	
return notify_fail("��Ŀ�ľ�񹦻��̫ǳ��\n");	
if ((int)me->query_skill("duanjia-sword", 1) > 300)	
return notify_fail("ʦ���ͽ��㵽����,�Ժ��Լ��ڼ���ϰ��\n");	
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("duanjia-sword",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
       return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
       return notify_fail("��������������μҽ���\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"duanjia-sword/" + action;
}

