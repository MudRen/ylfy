// bingxue-xinfa.c  ��ѩ�ķ�
// By lucas

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl;
	string *sname;
    int i;	
    skl = me->query_skills();
    sname = keys(skl);
    if ( me->query("gender") == "����" && me->query_skill("bingxue-xinfa",1) > 49) 	
        return notify_fail("���޸����ԣ���������������������ı�ѩ�ķ���\n");	
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ѩ�ķ���\n");
	
        for (i=0;i<sizeof(skl);i++){	
            if (sname[i]=="bingxue-xinfa") continue;	
            if (sname[i]=="yijing-force") continue;	
			if (sname[i]=="xixing-dafa") continue;
        if( SKILL_D(sname[i])->valid_enable("force") )	
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ѩ�ķ�����\n");
}
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ѩ�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxue-xinfa/" + func;
}


