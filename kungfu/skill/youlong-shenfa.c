// youlong-shenfa.c ������
// written by Xiang

inherit SKILL;

string *dodge_msg = (
{
	"ֻ��$nһ�С�������졹���ҽ������أ����塸ಡ������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"$nһ���������ĺ�����˫��һ�ţ�������ˮ������ݳ����ܿ���$N���������ơ�\n",
	"$nʹ�����������衹�����β�ס����,���ڶ��$N�Ĺ���\n",
	"$nʹ����������Ӱ��,$N��ǰһ�����Ѳ���$n��Ӱ\n"
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	if ((int)me->query_skill("honghua-shengong",1)<300)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ��������\n");
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("qi", 30);
	return 1;
}

