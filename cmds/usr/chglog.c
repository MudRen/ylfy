#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    string file = "/log/chglog.txt";
    if (! (int)SECURITY_D->valid_read(file,me) )
	return notify_fail("û���ҵ�/log/chglog.txt��\n");
    me->start_more(trans_color(read_file(file)));
    return 1;
}

int help(object me)
{
    write(@HELP
��������Բ鿴��ʦ��MUD���޸ĵ�����¼��
HELP);
    return 1;
}
