
inherit SKILL;
string *dodge_msg = (
{
	"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
	"����$n����������������һ���������$N��һ�С�\n",
	"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
	"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"����$n����һ�ã�$N��һ�����˸��ա�\n",
	"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
	"$n����΢�Σ��о����յرܿ���$N��һ�С�\n",
	"$n�������ĵ�����һ������ͷ΢��,�����ܹ���$N��һ�С�\n"
});
int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}
int valid_learn(object me)
{
	if ((int)me->query_skill("guiyuan-dafa",1) < 150)
		return notify_fail("��Ĺ�Ԫ�󷨻��̫ǳ��\n");
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 )
		return notify_fail("�������̫���ˣ������˷ɻ���ƾ��\n");
	me->receive_damage("qi", 30);
	return 1;
}