// yihun-dafa.c �ƻ��
// By Kayin@CuteRabbit Studio 99-4-15 18:58 new
inherit SKILL;

void create() { seteuid(getuid()); }
int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("yihun-dafa", 1);
	
	if( (int)me->query("shen") < 0 )
		return notify_fail("���а��̫�أ��޷������ƻ�󷨡�\n");
		
	if ( (int)me->query("per") < 20)
		return notify_fail("��ƾ����Ҳ��̶õ����󣿡�\n");
		
	if(me->query("gender") == "Ů��")
	{
		if(lvl>me->query("per")*15)
			return notify_fail("���ֻ��ѧ�������ˡ�\n");
	}
	else
	{
		if(lvl>me->query("per")*5)
			return notify_fail("���ֻ��ѧ�������ˡ�\n");
	}
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�ƻ��ֻ�ܿ�ѧϰ����ߡ�\n");
}
