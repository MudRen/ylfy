// lingxu-bu ���鲽
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ��"+HIG"ѩ������"NOR+"�������ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ��"+YEL"һ������"NOR+"����˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ��"+CYN"���л�Ӱ"NOR+"��������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
	"dodge"  : 80
]),
([	"action" : "$nһʽ��"+RED"��������"NOR+"����ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
	"dodge"  : 100
]),
([	"action" : "$nһʽ��"+HIG"����Ʈ��"NOR+"�������弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shaolin-shenfa");

	if (level < 120 )
		zhaoshu--;

	if (level < 80)
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}
int valid_learn(object me)
{
	return 1;
}
int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}
string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ����������鲽��\n");
	me->receive_damage("qi", 30);
	return 1;
}


