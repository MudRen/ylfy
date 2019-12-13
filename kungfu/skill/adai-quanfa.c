//adai-quanfa.c ����ȭ��
// By Kayin @ CuteRabbit Studio 99-4-16 16:22 new

inherit SKILL;
#include <ansi.h>
mapping *action = (
{
([	"action" : "$N����ֱ�����Ķ���$n,һʽ"HIM"������ˮ��,����ˮ��"NOR"����$nѸ�ٻ�����",
	"force" : 200,
    "attack":this_player()->query_skill("adai-quanfa",1),
    "dodge" : (int)this_player()->query_skill("dodge"),
    "damage" : (int)this_player()->query("age")*10,
	"lvl" : 0,
    "skill_name" : "ֱ����",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"����Ŷ,��Ŷ��"NOR"����$nѸ�ٻ���",
	"force" : 1200,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*20,
	"lvl" : 100,
    "skill_name" : "��Ŷ,��Ŷ",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"������,���ϡ�"NOR"����$nѸ�ٻ���",
	"force" : 1300,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*21,
	"lvl" : 110,
    "skill_name" : "����,����",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"������,������"NOR"����$nѸ�ٻ���",
	"force" : 1400,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*22,
	"lvl" : 120,
    "skill_name" : "����,����",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"����Ҫ��,��Ҫ����"NOR"����$nѸ�ٻ���",
	"force" : 1500,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*23,
	"lvl" : 130,
    "skill_name" : "��Ҫ��,��Ҫ��",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"��������,�����ˡ�"NOR"����$nѸ�ٻ���",
	"force" : 1600,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*24,
	"lvl" : 140,
    "skill_name" : "������,������",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"�����������ˡ�"NOR"����$nѸ�ٻ���",
	"force" : 1700,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*25,
	"lvl" : 150,
    "skill_name" : "����������",
    "damage_type" : "����"
	 ]),
([	"action" : "$Nһʽ"HIM"��������,�����ˡ�"NOR"����$nѸ�ٻ���",
	"force" : 1800,
    "dodge" : (int)this_player()->query_skill("dodge"),
    "attack":this_player()->query_skill("adai-quanfa",1),
    "damage" : (int)this_player()->query("age")*26,
	"lvl" : 160,
    "skill_name" : "ȥ����",
    "damage_type" : "��Ѩ"
	 ]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

int valid_combine(string combo)
{
	return combo=="adai-quanfa";
}

int valid_learn(object me)
{
	if(!me->query("couple/have_couple"))
		return notify_fail("�㻹û���������ˣ�����������еľ�Ҫ��\n");
	if (me->query_skill("adai-quanfa", 1) >= 300)
		return notify_fail("����İ���ȭ�����Լ��ڼ���ϰ����\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ��������֡�\n");
	if ((int)me->query("max_neili") < 30000)
		return notify_fail("�������̫�����޷�������ȭ����\n");
	if ((int)me->query_str()< 40)
		return notify_fail("��ı���̫�����޷�������ȭ����\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("adai-quanfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query_skill("unarmed", 1) <= me->query_skill("adai-quanfa",1))
		return notify_fail("��Ļ����������޷���ϰ����ȭ����\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ����\n");
	me->receive_damage("qi", 25);
	me->add("neili", -30);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	
	if( damage_bonus < 1 ) return 0;
	if( random( me->query_skill("unarmed") ) > random( victim->query_skill("force")) ) 
	{
		victim->receive_wound("qi", damage_bonus );
		return HIR "ֻ������Ŷ..Ŷ����������"+ victim->name()+"��������ĵ�����ȥ��\n" NOR;
	}
}
string perform_action_file(string action)
{
	return __DIR__"adai-quanfa/" + action;
}
