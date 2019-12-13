// qiankundanuoyi.c Ǭ����Ų��

inherit SKILL;

string *parry_msg = (
{
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
	"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
	"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
	"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = (
{
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
	"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
	"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
	"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage)
{
	return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	return notify_fail("Ǭ����Ų��ֻ��ͨ���� [0;1m?[1m?[0mǬ����Ų���ķ� [0;1m?[1m?[0m��ߡ�\n");
}

int practice_skill(object me)
{
	int lvl;
	lvl=me->query_skill("qiankundanuoyi",1);
	if(lvl<251)
		return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
	else return 1;
}

string perform_function_file(string func)
{
	return __DIR__"qiankundanuoyi/" + func;
}

