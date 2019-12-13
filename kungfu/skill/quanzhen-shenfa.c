// chaos-steps.c

inherit SKILL;

string *dodge_msg = (
{
	"$nһ�С��������ࡹ�����ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
	"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
	"$nʹ������ת��Ȩ�������弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
	"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С��綯��⡹������������������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
	"����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취��ȫ������\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	        ||	(int)me->query("neili") < 3 )
		return notify_fail("������������������������������ǲ�����\n");
	me->receive_damage("qi", 30);
//	me->add("neili", -3);
	return 1;
}
