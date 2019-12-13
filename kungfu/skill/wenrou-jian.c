// wenrou-jian.c ���ϸ�����ὣ
#include <ansi.h>
inherit SKILL;
mapping *action = (
{
([      "name": "����է��",
"action": "$Nʹһ��"HIR"��"BLINK+HIY"����է��"NOR+HIR"��"NOR"������$w����㴺������$n��$l��û����֪�������������Ҳ���޷��ֵ�",
"parry":   -40,
"dodge":   -40,
	"damage": 70,
"damage_type":  "����"
	 ]),
([      "name": "ϸ������",
"action": "$N���е�$wһ��"HIR"��"BLINK+HIB"ϸ������"NOR+HIR"��"NOR"������ϸ�꣬�޿ײ���Ĵ���$n��$l",
"parry":   -50,
"dodge":   -50,
	"damage": 50,
"damage_type":  "����"
	 ]),
([      "name": "���Ǵ���",
"action": "$N�趯$w��һ��"HIR"��"BLINK+HIG"���Ǵ���"NOR+HIR"��"NOR"����������������磬�˽���һ������$n��$l",
"parry":   -60,
"dodge":   -60,
	"damage": 100,
"damage_type":  "����"
	 ]),
([      "name": "������ˮ",
"action": "$Nһ������$w��ʹ��"HIR"��"BLINK+HIW"������ˮ"NOR+HIR"��"NOR"�����ɵð������ˣ�����Ԧ������$n��$l�̳�һ��",
"parry":   -70,
"dodge":   -70,
	"damage": 60,
"damage_type":  "����"
	 ]),
([      "name": "֯��Ū��",
"action": "$N����$w������ɢ��һ��"HIR"��"BLINK+HIC"֯��Ū��"NOR+HIR"��"NOR"���������ƣ�������$n��$l�����˲�֪�����Ժη�",
"parry":   -80,
"dodge":   -80,
	"damage": 90,
"damage_type":  "����"
	 ]),
([      "name": "��������",
"action": "$N�����������������������������$wֱָ$n$l��һ��"HIR"��"NOR+BLINK+MAG"��������"NOR+HIR"��"NOR"���̳��˾��춯�ص�һ��",
"parry":   -90,
"dodge":   -90,
	"damage": 50,
"damage_type":  "����"
	 ]),
});
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����ϸ�����ὣ����\n");
	if( !(ob = me->query_temp("weapon"))
	        ||      (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	        ||      (int)me->query("neili") < 5 )
		return notify_fail("�����������������û�а취��ϰ���ϸ�꽣����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -25);
	write("�㰴����ѧ����һ�����ϸ�꽣����\n");
	return 1;
}
int effective_level()
{
	return 20;
}
string *parry_msg = (
{
	"$n���ƹ��У��ҽ�����һ�С��麣���ġ������е�$v�ݺݿĿ���$N��$w��\n",
	"$n������������ס$N��$w��һ�С�����ĺĺ����ʹ$N���԰ѳ����е�$w��\n",
});
string *unarmed_parry_msg = (
{
	"$nʹ��һ�С������¶���������๥����ʹ$N��֪�ǹ����ء�\n",
	"$nһ�����е�$v��ʹ��һ�С��������á������е�$v������ƣ���ȫ��������ס��\n",
});
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return __DIR__"wenrou-jian/" + action;
}
