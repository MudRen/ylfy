inherit SKILL;
string *dodge_msg = (
{
	"ֻ��$nһ�С�"+HIC+"�����Ѷ�"+NOR+"�����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"$nһ����"+YEL+"��ˮƮ��"+NOR+"��������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
	"$nʹ����"+MAG+"Ʈѩ����"+NOR+"������һ��ƮȻ�ݳ��������ŵء�\n"
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
	if (me->query_skill("dodge", 1) <=me->query_skill("piaomiao-shenfa", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}
string query_dodge_msg(object me,string limb)
{
	me->set_temp("fight/dodge",2*me->query_skill("piaomiao-shenfa",1));
	return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ�����Ʈ������\n");
	me->receive_damage("qi", 30);
	return 1;
}
