#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int t = 1, i;
    int lvl = (int)me->query_skill("huaxue-dafa", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������Ļ�Ѫ�󷨡�\n");
    if(lvl<=100)
    {
        if (lvl > 10 && -(int)me->query("shen") < t * 60) 
            return notify_fail("ѧ��Ѫ�󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
    }
    else
    {
        if (-(int)me->query("shen") < (51200 + (lvl - 100) * 500)) 
            return notify_fail("ѧ��Ѫ�󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
    }
	
	if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ���򻹲������޷���ữѪ�󷨡�\n");
    
	skl = me->query_skills();    
	sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ѫ�󷨣�\n");
    }

    return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ѫ��ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

