// guiyuan-tunafa.c ���ư� ��Ԫ���ɷ�

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

	if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧ��Ԫ���ɷ���\n");
    if ( me->query("gender") == "����" && me->query_skill("guiyuan-tunafa",1) > 49)	
        return notify_fail("���޸����ԣ���������������������Ĺ�Ԫ���ŷ���\n");	
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��Ԫ���ɷ���ʲ�ᣡ\n");

        skl = this_player()->query_skills();	
        sname  = keys(skl);	
    for (i=0;i<sizeof(skl);i++){	
        if (sname[i]=="yijing-force") continue; 	
        if (sname[i]=="guiyuan-tunafa") continue; 
        if (sname[i]=="xixing-dafa") continue;      	
        if( SKILL_D(sname[i])->valid_enable("force") )	
		    return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ���ɷ�����\n");
              }
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("��Ԫ���ŷ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"guiyuan-tunafa/" + func;
}
