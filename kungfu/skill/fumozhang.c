//fumozhang.c ����ħ�ơ�by yushu@SHXY

inherit SKILL;
#include <ansi.h>
mapping *action = (
{
([   "action": "$Nǰ���߳������Ƚż��أ�һʽ"HIC"����ħ���¡�"NOR"������ֱ��������$n����������·",
    "dodge": -5,
    "parry":  -5,
	"neili": 80,
    "damage_type":  "����"
	 ]),
([      "action": "$N���ƻ�һ��Բ��һʽ"HIR"����Ѫ���ġ�"NOR"������б������������$n����ǰ��Ѩ",
    "dodge": -25,
    "parry": -25,
	"neili": 70,
    "damage_type":  "����"
	 ]),
([   "action": "$Nʹһʽ"HIM"������Ⱥħ��"NOR"�����������������ɺ����һ��˦����ն��$n��$l",
    "dodge": -5,
    "parry": -5,
	"neili": 60,
    "damage_type":  "����"
	 ]),
([      "action": "$N���ƻ��أ���ȭ�����󷢣�һʽ"HIY"����ճ�����"NOR"����������$n��$l",
	"dodge": 5,
	"parry": 5,
	"neili": 100,
    "damage_type":  "����"
	 ]),
([  "action": "$Nʹһʽ"HIG"������ǧ����"NOR"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
    "dodge":  -5,
    "parry":  -5,
	"neili": 90,
     "damage_type":  "����"
	 ]),
([   "action": "$N���Ʊ�������һ������һʽ"HIW"��Ⱥħ���ס�"NOR"��˫�Ƽ�����$n�ļ�ͷ",
	"dodge": 5,
	"parry": 5,
	"neili": 60,
    "damage_type":  "����"
	 ]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
	  )
		return notify_fail("����ħ�Ʊ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}
string perform_action_file(string func)
{
	return __DIR__"fumozhang/" + func;
}
