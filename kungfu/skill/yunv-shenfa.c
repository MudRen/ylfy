// yunv-shengfa ��Ů��
#include <ansi.h>;
inherit SKILL;

string *dodge_msg = (
{
	HIW"$nһ�С������貨���������趯����ס����ȥ������ƮƮ�������⣬�����$N��һ�С�\n"NOR,
	HIR"$n��ȻһЦ�����˾�����$N��Ϊ���ˣ����²���һ�٣�$n�ѽ��⡸һЦ�����֮�ƣ��ܿ���$N���������ơ�\n"NOR,
	HIG"$nʹ����������ơ���������Σ��Ų�������������$N�����\n"NOR,
	HIC"$n�����أ��ۿ�$Nɱ�п���Ϯ������ϥһ�䣬�����߳�������һ�С����ҹ�����������ѽ���ƽ�ƣ�����һ�ԡ�\n"NOR,
	HIY"$nһʽ������׹¥�����������ػ��У�����˷�����˼����$N�Ĺ�����Ȼ�˿ա�\n"NOR,
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(object me,string limb)
{
	if (me) me->set_temp("fight/dodge",random(3*me->query_skill("yunv-shenfa",1)));
	return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me)
{
	if((int)me->query("qi") < 30 )
		return notify_fail("�����Ϣһ���ˣ��Ȼ�������Ů���ɡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}

