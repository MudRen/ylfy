// kunlun-zhang.c ������

#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ��"+(order[random(13)])+"�������ɽ��"NOR"������$n��$l",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 100,
        "lvl" : 0,
        "skill_name" : "�����ɽ",
        "damage_type" : "����"
]),
([      "action" : "$N˫������һ��"+(order[random(13)])+"�������Ƶ���"NOR"��һ�ƻ���$n���ţ���һ��ȴ����$n���ؿ�",
        "force" : 230,
        "dodge" : 5,
        "parry" : 10,
        "damage" : 120,
        "lvl" : 20,
        "skill_name" : "�����Ƶ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ������Ī�⣬һ��"+(order[random(13)])+"����粻����"NOR"��ǰ�����ң�˲Ϣ֮����$n����������һʮ����",
        "force" : 300,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 150,
        "lvl" : 38,
        "skill_name" : "��粻��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ����Х������һ�ƣ�һ��"+(order[random(13)])+"��ɽ��·ת��"NOR"������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ��",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 180,
        "lvl" : 55,
        "skill_name" : "ɽ��·ת",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƽ����������ޣ�һ��"+(order[random(13)])+"�������޷졹"NOR"������$n��$l",
        "force" : 350,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 200,
        "lvl" : 72,
        "skill_name" : "�����޷�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"����ɽ�Ϻӡ�"NOR"������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
       "force" : 400,
        "dodge" : 25,
        "parry" : 30,
        "damage" : 230,
        "lvl" : 87,
        "skill_name" : "��ɽ�Ϻ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫���뻮������˫�����ƣ�һ��"+(order[random(13)])+"�������ء�"NOR"��һ����ɽ������������ֱ��$n����",
        "force" : 450,
        "dodge" : 30,
        "parry" : 35,
        "damage" : 260,
        "lvl" : 101,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�������ת��һ��"+(order[random(13)])+"����ɽѩƮ��"NOR"����Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 520,
        "dodge" : 45,
        "parry" : 40,
        "damage" : 300,
        "lvl" : 120,
        "skill_name" : "��ɽѩƮ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry" ||  usage=="strike"; }

int valid_learn(object me)
{
 
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("xuantian-wuji", 1) < 120)
         return notify_fail("��������޼�����򲻹����޷��������ơ�\n");
			
    if ((int)me->query("max_neili") < 800)
        return notify_fail("���������Ϊ�������޷��������ơ�\n");
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
        level   = (int) me->query_skill("kunlun-zhang",1);
        
          for(i = sizeof(action); i > 0; i--)
                                 if(level > action[i-1]["lvl"]) 
               return action[NewRandom(i, 20, level/5)];
                              
}

int practice_skill(object me)
{

        int lvl = me->query_skill("kunlun-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kunlun-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level;
    level = (int) me->query_skill("xuantian-wuji",1);

if (random(4)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",damage_bonus + 100);
        victim->receive_wound("qi",damage_bonus + 100);
	return HIB"$N��̤���Բ�,����̫�Ҿ�,$Nһ����Х��$n˫��һ�ڣ��³�һ����Ѫ!\n"NOR;
}
}