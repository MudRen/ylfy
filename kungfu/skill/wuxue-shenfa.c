//  ��ѩ��

inherit SKILL;

string *dodge_msg = (
{
	"$nһ������ת����������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
	"$nʹ��һ�С�����׽Ӱ������Ȼ�������࣬���$N���˸��ա�\n",
	"$n����һҡ���ó�������Ӱ��һ�С���Ӱ���ء������$N�Ĺ��ơ�\n",
	"$nһ�С�����Ʈ�졹����Ծ��ٿ��������$N���\n",
	"$n��һҡ����һ�Σ�һ�С������޳���������������\n",
	"$n˫��һ�㣬бб����ʹ�����������桹������$N��ࡣ\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") ;
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
	if( (int)me->query("qi") < 30 )
		return notify_fail("�������̫���ˣ���������ѩ����\n");
	if (me->query_skill("wuxue-shenfa", 1) < 30)
		me->receive_damage("qi", 10);
	me->receive_damage("qi", 20);
	return 1;
}
