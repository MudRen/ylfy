//shayi-xinfa ɱ���ķ�

#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage=="force";
}
int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("shayi-xinfa", 1);
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı�ڤ�񹦡�\n");
	if (me->query_skill("force",1)<=lvl)
		return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	if (me->query_skill("force",1)<30)
		return notify_fail("��Ļ����ڹ���������������ѧɱ���ķ���\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="shayi-xinfa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="yijing-force") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧɱ���ķ�����\n");
	}
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("ɱ���ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"shayi-xinfa/" + func;
}

mapping exercise_msg(object me)
{
	return ([
            "status_msg" : HIB + me->name()+"ɱ����������������" NOR,
            "start_my_msg" : HIR"����������������ɱ������������ʼ��������ת��\n"NOR,
            "start_other_msg" : me->name()+"ȫ��������ȫ�������������˳����������е�ɱ���ޱ�������\n",
            "halt_msg" : "$Nüͷ��չ��ɱ����ʧ���ָ���ƽʱ��ģ����\n",
            "end_my_msg" : "�޾���ɱ�⻺��ɢ��ȫ�������ۣ�������һ������\n",
            "end_other_msg" : "ֻ��"+me->name()+"���۾�����ɱ�⣬�������ָֻ���ԭ״��\n"
	        ]);
}
