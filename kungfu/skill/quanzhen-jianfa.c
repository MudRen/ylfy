// quanzhen-jian.c ȫ�潣��
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$Nʹһʽ"+(order[random(13)])+"��̽��������"NOR"������$w�������Һ�ɨ����$n��$l",
        "force" : 120,
        "dodge" : 0,
        "damage": 130,
        "lvl" : 0,
        "skill_name" : "̽������",
        "damage_type":  "����"
]),
([      "action":"$N̤��һ����"+(order[random(13)])+"���ɨҶ��"NOR"������$w���������һ����������$n��$l",
        "force" : 140,
            "dodge" : 10,
        "damage": 150,
        "lvl" : 9,
        "skill_name" : "�ɨҶ",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һ��"+(order[random(13)])+"��˳ˮ���ۡ�"NOR"��ббһ�������ó�������$n��$l",
        "force" : 160,
           "dodge" : 5,
        "damage": 170,
        "lvl" : 18,
        "skill_name" : "˳ˮ����",
        "damage_type":  "����"
]),
([      "action":"$N����$w����������Ȧ��һʽ"+(order[random(13)])+"���ǳڵ�����"NOR"��һ���������$n��$l",
        "force" : 180,
        "dodge" : 10,
        "damage": 195,
        "lvl" : 27,
        "skill_name" : "�ǳڵ���",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ"+(order[random(13)])+"���׺����᡹"NOR"��������չ������$w����$n��$l",
        "force" : 220,
        "dodge" : 15,
        "damage": 210,
        "lvl" : 36,
        "skill_name" : "�׺�����",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬һʽ"+(order[random(13)])+"������Į����"NOR"����׼$n��$lбб����",
        "force" : 260,
        "dodge" : 5,
        "damage": 220,
        "lvl" : 44,
        "skill_name" : "����Į��",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ"+(order[random(13)])+"�������仨��"NOR"�����󼱶�������������⣬����$n��$l",
        "force" : 320,
        "dodge" : 5,
        "damage": 245,
        "lvl" : 52,
        "skill_name" : "�����仨",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ"+(order[random(13)])+"����Ʒ��̨��"NOR"��$w��ն�������缲�������$n���ؿ�",
        "force" : 380,
        "dodge" : 5,
        "damage": 265,
        "lvl" : 60,
        "skill_name" : "��Ʒ��̨",
        "damage_type":  "����"
]),
([      "action":"$Nʹһʽ"+(order[random(13)])+"��������ء�"NOR"������$w������$n���ؿڣ������ɵ�",
        "force" : 380,
        "dodge" : 115,
        "damage": 285,
        "lvl" : 70,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$w����һ�������Ļ��ߣ�����$n��$l��ȴ��һ��"+(order[random(13)])+"����ʷ������"NOR"",
        "force" : 380,
        "dodge" : 115,
        "damage": 300,
        "lvl" : 80,
        "skill_name" : "��ʷ����",
        "damage_type":  "����"
]),
([      "action":"$N�ؽ����أ�ʹһʽ"+(order[random(13)])+"��������项"NOR"���������$w��$n����",
        "force" : 380,
        "dodge" : 115,
        "damage": 320,
        "lvl" : 90,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N��������һʽ"+(order[random(13)])+"�������߶���"NOR"��$w�Ӳ���˼��ĽǶȴ���$n",
        "force" : 380,
        "dodge" : 115,
        "damage": 340,
        "lvl" : 114,
        "skill_name" : "�����߶�",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ"+(order[random(13)])+"���ϵ紩�ơ�"NOR"��$wͻȻ���������һƬ���Χ��$nȫ��",
        "force" : 380,
        "dodge" : 115,
        "damage": 265,
        "lvl" : 129,
        "skill_name" : "�ϵ紩��",
        "damage_type":  "����"
]),
([	"action":"$N�ζ�$w��̤���ţ���ƫ�棬������˼�����һ�������ޱȵ�"+(order[random(13)])+"���ֻ�������"NOR"������ʵ�ң��ѵ���$n$l",
	"force" : 150,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 215,
	"lvl" : 105,
	"skill_name" : "�ֻ�����",
	"damage_type":	"����"
]),
([	"action":"$Nʹһ��"+(order[random(13)])+"������������"NOR"����������Ʈ������$w����ʵʵ�ó����㺮������$n$l",
	"force" : 180,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 225,
	"lvl" : 109,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$N������$nһת����Ȼһʽ"+(order[random(13)])+"���ɨҶ��"NOR"����$w������콣Ӱ��Ю�ž�����$nɨȥ",
	"force" : 250,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 260,
	"lvl" : 125,
	"skill_name" : "�ɨҶ",
	"damage_type":	"����"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ��"+(order[random(13)])+"���˼����ġ�"NOR"��$w�ó����컨�꣬Ѹ����������$n��$l",
	"force" : 450,
	 "dodge" : 20,
	"parry" : 20,
	"damage": 200,
	"lvl" : 135,
	"skill_name" : "�˼�����",
	"damage_type":	"����"
]),
([	"action":"$N�������Ž���������̤��һ��"+(order[random(13)])+"�������롱"NOR"����б�̣�$w��ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"force" : 420,
	 "dodge" : 8,
	"parry" : 8,
	"damage": 320,
	"lvl" : 145,
	"skill_name" : "������",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧȫ�潣����\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("quanzhen-jianfa", 1))
        return notify_fail("��Ļ����������̫ǳ��\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("quanzhen-jianfa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/3;
    return a_action;

}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("�������������ȫ�潣����\n");
          if ((int)me->query("qi") < 40)
                return notify_fail("�������������ȫ�潣����\n");
          me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                                                                                                                
	int level;
    level = (int) me->query_skill("qixing-array",1);

if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	victim->start_busy(3);
	return HIR"$N̤���ţ���ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;
}
}
int ob_hit(object ob, object me, int damage)
{
        string msg;
        int j;
        int level;
        level = (int) me->query_skill("qixing-array",1);

if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{
	ob->start_busy(3);
    msg = HIG"$N������λ����ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;
    message_vision(msg, me, ob);
           return j;
}       
}
string perform_action_file(string action)
{
        return __DIR__"quanzhen-jianfa/" + action;
}
