//zhenfeng-xinfa.c ������ķ���

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "����" )
                return notify_fail("������ķ��������������������Թ����޸�����֮������޵ã�\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("������ķ���ȫ��һ�����䣬��Υ����徲֮����"
                        +RANK_D->query_respect(me)+"������ذɡ�\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ķ���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhenfeng-xinfa/" + func;
}
