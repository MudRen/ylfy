// swsb-shou.c ����������

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$Nһ��"HIW"���޿ײ��롹"NOR"��$n��ǰ���ᶼ��$w��Ӱ��ͬʱ��$nȫ�������Ѩ",
	"dodge": (int)this_player()->query_skill("whip")/10,
	"damage":(int)this_player()->query_skill("whip"),
	"lvl" : 0,
	"skill_name" : "�޿ײ���",
	"damage_type":	"��Ѩ"
]),
([	"action":"$Nһ��"HIY"������������"NOR"������$w����$n�����ƫ��Ѩ����",
	"dodge":(int)this_player()->query_skill("whip")/5,
	"damage":(int)this_player()->query_skill("whip")*2,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type":	"��Ѩ"
]),
([	"action":"$Nһ��"HIC"��������Ϊ��"NOR"��$wר��$n��������֮����",
	"dodge":(int)this_player()->query_skill("whip"),
	"damage":(int)this_player()->query_skill("whip")*3,
	"lvl" : 100,
	"skill_name" : "������Ϊ",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("����������㣬û�а취������������, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ������������������\n");

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
	level   = (int) me->query_skill("swsb-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������������֡�\n");
	me->receive_damage("qi", 5);
	return 1;
}