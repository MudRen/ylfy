// wangxiang-fufa ���븫��
// marry 99.8
#include <ansi.h>
inherit SKILL;

mapping *action = (
{
([ "name":   ""MAG"�̹ſ���"NOR"",
    "action": "$Nһʽ��"MAG"�̹ſ���"NOR"���޻�������$n��$l��",
	"force": 50,
    "dodge":  -10,
	"damage": 100,
	"lvl"   : 0,
    "damage_type":  "����"
	 ]),
([ "name":   ""HIM"����ն��"NOR"",
   "action": "ֻ��$Nһ�С�"HIM"����ն��"NOR"������$w����ʮ����$n��ȥ��",
	"force":  250,
    "dodge":  -1,
	"damage": 250,
	"lvl"   : 150,
    "damage_type":  "����"
	 ]),
([ "name":   ""HIG"����Ū��"NOR"",
    "action": "$N������ɫһ�䣬ʹ��һ�С�"HIG"����Ū��"NOR"��������$w����������$n��$l",
	"force":  300,
	"dodge":  10,
	"damage": 300,
	"lvl"   : 250,
    "damage_type":  "����"
	 ]),
([ "name":   ""HIB"����"NOR"",
    "action": "$N����$w������ת��һ�С�"HIB"����"NOR"���ݺݵ�����$n��",
	"force":  350,
	"dodge":  30,
	"damage": 350,
	"lvl"   : 350,
    "damage_type":  "����"
	 ]),
([ "name":   ""WHT"�˷�����"NOR"",
    "action": "$N��Ȼ����������$Nһʽ��"WHT"�˷�����"NOR"��������$w��Ȼ����$n��$l��",
	"force":  400,
	"dodge":  50,
	"damage": 400,
	"lvl"   : 400,
    "damage_type":  "����"
	 ]),
});


int valid_enable(string usage)
{
	return usage=="axe" ||  usage=="parry";
}
int valid_learn(object me)
{
	object weapon;
	int lvl = (int)me->query_skill("wangxiang-fufa", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	if ( me->query("gender") != "����" )
		return notify_fail("���ֲ���������ʲô���븫����\n");
	if ((me->query("family/master_id")!="xiao jin")&&
	        (me->query("family/master_id")!="chu huan")&&
	        (me->query("family/master_id")!="xuanyuan liang"))
		return notify_fail("�Ǳ������ڵ����޷�ѧϰ��\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("�����������̫���ˡ�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("�����������̫���ˡ�\n");
	}

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("����������㣬û�а취�����븫��, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("axe", 1) < 50)
		return notify_fail("��Ļ����������̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	        || ( string)weapon->query("skill_type") != "axe" )
		return notify_fail("���������һ����ͷ������������\n");

	return 1;
}


string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
	int skill;
	if ((me->query("family/master_id")!="xiao jin")&&
	        (me->query("family/master_id")!="chu huan")&&
	        (me->query("family/master_id")!="xuanyuan liang"))
		return notify_fail("�Ǳ������ڵ����޷���ϰ��\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("����������������븫����\n");
	if( skill > 100 && me->query("shen") < 1)
		return notify_fail("�����书�����������¡�\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{

	if( damage_bonus < 100 ) return 0;
	if( random( me->query_skill("axe") ) > random( victim->query_skill("force")) && me->query("family/family_name") == "����������" )
	{
		victim->receive_wound("qi", (damage_bonus ) * 2 );
		return HIR "ֻ������"HIY""BLINK"��"NOR""HIR"����һ�����죬$w"HIR"��Ȼ��������Ƥ�⣡\n" NOR;
	}
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("wangxiang-fufa",1)) > 399 &&me->query("neili") > 150 && me->query("family/family_name") == "����������" )
	{
		me->add("neili", -150);
		return ([
            "action": ""HIB"��Ȼ$N���ۺ������䣬����$w"HIB"ˣ���컨��׹��\n"
		            "$n"HIB"�������飬ֻ�����Լ��ƺ��Ѿ��޴����ӣ��ۿ�һƬɱ�������Լ���\n"NOR"",
		            "force": 500,
		            "damage": 500,
            "damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
	return __DIR__"wangxiang-fufa/" + action;
}
