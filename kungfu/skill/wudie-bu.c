// �����
// wudie-bu

inherit SKILL;
#include <ansi.h>

string *dodge_msg = (
{
	"����$nһ�С�"HIR"����"HIW"ʳ��"HIB"������"NOR"�����ɶ����\n",
	"ͻȻ$n��"WHT""BLINK"����"NOR"���裬һ�С�"HIY"����"HIG"���"HIM"��ӳ��"NOR"��������$N�Ĺ�����\n",
	"ֻ����$n����һ�䣬ʹ����"HIY"����"CYN"�м�"HIR"��δ��"NOR"�������ƮƮ��������\n",
	"ȴ��$n�������ŵ�ʹ����"HIM"�ž�"YEL"����"HIW"������"NOR"���������㣬�ܿ��˹�����\n"
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 45 )
		return notify_fail("�������̫���ˣ��������������\n");
	if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
		return notify_fail("����������Բ���������Զ�޷�ѧ���������\n");

	me->receive_damage("qi", 35);
	return 1;
}

