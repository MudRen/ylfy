inherit SKILL;
string *dodge_msg = (
{
	"$n����һ�Σ���̤�޳���λ���������ɵĶ㿪��$N�����ޱȵĹ�����\n",
	"$n��$N�Ĺ����Ӷ�������ֱ��$N����ʽ����Ų��Ų�æ����������һ������Ȼ�������ˡ�\n",
	"ֻ��$n��̤����λ�ã��Ҳ�̫���鸡������������԰��ɢ����㿪��$Nһ����һ�С�\n"
});
int valid_enable(string usage)
{
	return (usage == "dodge");
}
int practice_level()
{
	return 60;
}
int valid_learn(object me)
{
	if (me->query_skill("dodge", 1) <=me->query_skill("lingyunbu", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}
string query_dodge_msg(object me,string limb)
{
	if (me) me->set_temp("fight/dodge",me->query_skill("lingyunbu",1)+random(me->query_skill("lingyunbu",1)));
	return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ�������ϰ���Ʋ�����\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lingyunbu/" + action;
}


