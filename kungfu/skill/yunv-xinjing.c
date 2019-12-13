// yunv-xinjing.c ��Ů�ľ�
inherit FORCE;
#include <ansi.h>
int valid_enable(string usage)
{
	return usage == "force";
}

#include "force.h"

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("yunv-xinjing", 1);
	if (me->query_skill("yunv-xinjing",1)<120)
		return notify_fail("��Ů�ľ�ֻ�ܿ��������ϰ��\n");
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ������������������������Ů�ľ��񹦡�\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="yunv-xinjing") continue;
		if (sname[i]=="yunv-xinfa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ľ�����\n");
	}
	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��Ů�ľ�ֻ�ܿ��������ϰ��\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinjing/" + func;
}

mapping exercise_msg(object me)
{
	return ([
            "status_msg" : HIB + me->name()+"��̬���ţ���̬���䡣"NOR,
            "start_my_msg" : "���������һ�����������۾���������Ů�ľ�����Ϣ�������п�ʼ��ת��\n",
            "start_other_msg" :HIB + me->name()+"��̬ͻȻ��ʼ��������ޱȣ����������ֱ�������쳣��\n"NOR,
            "halt_msg" : HIB"$N��Ϣһת��Ѹ��������ֹͣ����Ϣ����ת��\n"NOR,
            "end_my_msg" : "���������������뵤������۾������������һ������\n",
            "end_other_msg" : HIB "ֻ��"+me->name()+"�����۾���������³���һ��������̬�ָ���Ȼ��\n"NOR
	        ]);
}

