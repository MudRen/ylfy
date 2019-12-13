// linji-zhuang.c �ټ�ʮ��ׯ

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
    mapping skl;	
    string *sname;	
    int i;	

    if ( (me->query("family/family_name") != "������"))
        return notify_fail("�㲻�Ƕ��ҵ��ӣ�������ϰ�ټ�ʮ��ׯ��\n");
				    
    if ( me->query("gender") == "����" )
        return notify_fail("���޸����ԣ�����������������ᴿ��������ķ����ڹ��ķ���\n");

    if ((int)me->query_skill("force", 1) < 20)
        return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");

        skl = this_player()->query_skills();	
        sname  = keys(skl);	
      for (i=0;i<sizeof(skl);i++){	
        if (sname[i]=="yijing-force") continue;	
        if (sname[i]=="linji-zhuang") continue;	
		if (sname[i]=="xixing-dafa") continue;
        if( SKILL_D(sname[i])->valid_enable("force") )	
	         return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�ټ�ʮ��ׯ����\n");
}
	return 1;
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}
