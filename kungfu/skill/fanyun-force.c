inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    string master;
    int lvl = (int)me->query_skill("fanyun-force", 1);
    master=me->query("family/master_id");
    
                    
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ķ����񹦡�\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷���ᷭ���񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�����������ʵ����ѧ��ȥ���߻���ħ�ġ�\n");
 return 1;
}
string exert_function_file(string func)
{
    return __DIR__"fanyun-force/" + func;
}
int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

