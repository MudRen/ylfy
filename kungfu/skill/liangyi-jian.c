//liangyi-jian.c ���ǽ���

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "name":   "��������",
    "action" : "$N���⽣â������һ��"+(order[random(13)])+"���������ء�"NOR"������$w�����´󿪴��أ�һ����������$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "��������",
    "action" : "$N����Ȧת��һ��"+(order[random(13)])+"������������"NOR"������$wƽչ�´̣�һ�����Ữ��$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "Ԩ����ǳ",
    "action" : "$N��������������������������$wʹ��һʽ"+(order[random(13)])+"��Ԩ����ǳ��"NOR"����$n��$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "ˮ�����",
    "action" : "$N������ָ��������ת��һ��"+(order[random(13)])+"��ˮ����ơ�"NOR"ֱȡ$n��$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "�ƺ�����",
    "action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+(order[random(13)])+"���ƺ����¡�"NOR"�������������$n��$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "���ѵ�ׯ",
    "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ"+(order[random(13)])+"�����ѵ�ׯ��"NOR"ԾԾ����Ʈ��$n��$l",
    "force" : 120,
    "dodge" : 125,
    "damage" : 320,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "name":   "��������",
    "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+(order[random(13)])+"���������ǡ�"NOR"����������֮�ƣ�����$n��$l",
    "force" : 110,
    "dodge" : 115,
    "lvl" : 0,
    "damage" : 400,
    "damage_type" : "����"
]),
([  "name":   "��ϵ�̳�",
    "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+(order[random(13)])+"����ϵ�̳���"NOR"���¶��ϴ���$n��$l",
    "force" : 150,
    "dodge" : 135,
    "damage" : 400,
    "lvl" : 0,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
	object weapon;
    if (me->query_skill("sword", 1) <=me->query_skill("liangyi-jian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧ���ǽ�����\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 50 )
		return notify_fail("��������޼����̫ǳ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
     return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;
	
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������ǽ�����\n");
    me->receive_damage("qi", 10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level;
	object weapon;
	weapon = me->query_temp("weapon");
    level = (int) me->query_skill("xuantian-wuji",1);
      
if (random(4)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",damage_bonus +300 );
        victim->receive_wound("qi",damage_bonus + 100);
	return HIB"$N��̤���Բ�,����̫�Ҿ�,$Nһ����Х��$n˫��һ�ڣ��³�һ����Ѫ!\n"NOR;
}
}