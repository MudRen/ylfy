// yugalism.c

inherit SKILL;

void create()
{
	seteuid(getuid());
}
string type()
{
	return "knowledge";
}
int valid_learn(object me)
{
	int lvl;

	lvl = (int)me->query_skill("yugalism",1);

	if(me->query("gender") == "����" && lvl > 30)
		return notify_fail("�����һ�������������Ժ���ԭ���������֮�����㣬�޷��������������仯֮����\n");
	if(me->query("gender") == "����" && lvl > 30)
		return notify_fail("�����һ�������������Ժ���ԭ���������֮�����㣬�޷��������������仯֮����\n");

	if(me->query("class") == "taoism")
		return notify_fail("������"+RANK_D->query_respect(me) +"������ң���ôȴ��ѧ�����ķ���\n");
	if ( me->query_skill("taoism",1))
		return notify_fail("�㲻��ɢ�ˡ���ѧ�ķ���������ѧ����������ķ�������\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
