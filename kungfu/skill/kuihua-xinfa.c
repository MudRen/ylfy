// kuihua-xinfa.c �����ķ�
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{

	return notify_fail("�����ķ�ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
}
int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"kuihua-xinfa/" + func;
}

void skill_improved(object me)
{
	int s;
	s=me->query_skill("kuihua-xinfa",1);
	if (s%10==0)
	{
		tell_object(me, HIW"��Ŀ������Ѿ���������"+HIY+CHINESE_D->chinese_number(s/10)+HIW+"���ˡ�\n" NOR);
	}
}

