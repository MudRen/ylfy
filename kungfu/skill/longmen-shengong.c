// made by lks;

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("longmen-shengong", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������Ļ�Ѫ�󷨡�\n");

	 if ( me->query("class") == "bonze" )
        return notify_fail("�����񹦽���ɱ�����У���Υ���֮�⣬"+RANK_D->query_respect(me)+"���޴˹������������\n");

	 if( (int)me->query_skill("longmen-shengong", 1) > 30 )
		return notify_fail("������ֻ��ͨ����������ߡ�\n");

	if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ���򻹲������޷���������񹦡�\n");
    
	skl = me->query_skills();
    
	sname  = keys(skl);
    
	for (i=0;i<sizeof(skl);i++){
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣�\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����񹦲���ͨ����ϰ�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"longmen-shengong/" + func;
}
