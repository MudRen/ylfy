// xixing-dafa.c ���Ǵ�
// By suimeng
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
  
    int lvl = (int)me->query_skill("xixing-dafa", 1);
    if ( me->query("gender") == "����")
        return notify_fail("���޸����ԣ���������������������Ǵ󷨡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("��Ļ����ڹ���������������ѧ���Ǵ󷨡�\n");
    if ( me->query_skill("kuihua-xinfa",1) || me->query_skill("beiming-shengong",1)|| me->query_skill("huagong-dafa",1))
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ���Ǵ󷨣���\n");
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("���Ǵ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"xixing-dafa/" + func;
}

int help(object me)
{
        write(HIC"\n���Ǵ󷨣�"NOR"\n");
        write(@HELP

    ������̺�ľ�µ�һ���ڹ���

    ���Ǵ󷨴��Ա���������ң�ɣ���Ϊ��ڤ�񹦺ͻ�������
·�������Ӵ�����Ϻ������ɷֱ��䣬�϶�Ϊһ����Ϊ���Ǵ󷨡�
��Ҫ�Ǽ̳��˻�����һ·����ϰ�ߵ���ﳣ����䣬������ȣ�
����������ȿ���ˮ��������Ϣ��ɢ֮��������Ѩ��
    ���Ǵ�ֻ�ܰ�������Ϊʦѧϰ�������൱��Ե����ѧ����

        ѧϰҪ��
                �����ڹ�100��

HELP
        );
        return 1;
}
