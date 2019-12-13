// �嶾��

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
	if ( (int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����嶾�񹦡�\n");
        skl = me->query_skills();
        sname = keys(skl);
        
	 for (i=0;i<sizeof(skl);i++){
	    if(sname[i] == "wudu-shengong") continue;
		if(sname[i] == "yijing-force") continue;
		if(sname[i]=="xixing-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
             return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�嶾�񹦣���\n");
    }

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�嶾��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"wudu-shengong/" + func;
}
