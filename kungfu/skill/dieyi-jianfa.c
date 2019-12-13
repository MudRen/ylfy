// ������
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$N����$w�������$n��$l��Ѹ���ޱ�",
        "force"  : 100,
        "dodge"  : 10,
        "damage" : 170,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ�������е�$w����һ����������Ȼ����$n",
        "force"  : 120,
        "dodge"  : 15,
        "damage" : 284,
        "lvl"    : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ������ಽ�����е�$wб��$n��$l",
        "force"  : 140,
        "dodge"  : 30,
        "damage" : 300,
        "lvl"    : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nȴ���Ჽ�����е�$w�Ƶ��ɵ����ƽ��ǽ�������ֱ��$n",
        "force"  : 160,
        "dodge"  : 38,
        "damage" : 310,
        "lvl"    : 75,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�����ļ��죬ֻ�ϵ�$n�ۻ����ң��벻֪�Ӻι���",
        "force"  : 180,
        "dodge"  : 45,
        "damage" : 325,
        "lvl"    : 100,
        "damage_type" : "����"
]),
([      "action" : "$N�������𣬽�����ָ�����������ƣ�ֱ��$n��$l",
        "force"  : 200,
        "dodge"  : 50,
        "damage" : 330,
        "lvl"    : 130,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��������һ�̣�û���κλ��ɣ�Ȼ�����ǿ�ò���˼��",
        "force"  : 220,
        "dodge"  : 55,
        "damage" : 440,
        "lvl"    : 160,
        "damage_type" : "����"
]),
([      "action" : "$N��̾һ�������е�$w����һ����������$n",
        "force"  : 240,
        "dodge"  : 70,
        "damage" : 550,
        "lvl"    : 200,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�����е�$w���������������������$n",
        "force"  : 260,
        "dodge"  : 85,
        "damage" : 555,
        "lvl"    : 225,
        "damage_type" : "����"
]),
([  "action" : "$Nһ����Ц������$w�û��������ǵ㣬��֪����$n�ĺδ�",
        "force"  : 320,
        "dodge"  : 90,
        "damage" : 780,
        "lvl"    : 250,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query_skill("wudie-xinjing", 1) < 50)
		return notify_fail("��ġ�����ľ�����򲻹����޷�ѧ������������\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���������������\n");
	if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
		return notify_fail("����������Բ���������Զ�޷�ѧ��������������\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("dieyi-jianfa",1);
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
		return notify_fail("�������������������������\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������������������\n");
	me->receive_damage("qi", 30);
	me->add("neili",-15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dieyi-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( userp(victim) )
	{
		if( random(me->query("jiali")) * 2 > victim->query("jiali")) return 0;

		victim->receive_wound("qi", random( me->query("jiali")));
		return MAG BLINK "��������ৡ�һ������������紵������Ȼ��$nѪð���ɣ����������ˣ�\n" NOR;
	}
	else
	{
		if( damage_bonus < 1 ) return 0;

		if( random( me->query_skill("sword") ) > random( victim->query_skill("force")) && me->query_skill_mapped("force") == "wudie-xinjing" )
		{
			victim->receive_wound("qi", damage_bonus );
			return MAG BLINK "��������ৡ�һ������������紵������Ȼ��$nѪð���ɣ����������ˣ�\n" NOR;
		}
	}
}