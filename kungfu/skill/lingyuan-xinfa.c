// lingyuan-xinfa.c ��Ԫ�ķ�

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��Ԫ�ķ�ֻ����ѧϰ�������������ȡ�\n");
}

string exert_function_file(string func)
{
    return SKILL_D("lingyuan-xinfa/") + func;
}
