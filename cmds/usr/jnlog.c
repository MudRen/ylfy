#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    string file = "/log/jnlog.txt";
    if (! (int)SECURITY_D->valid_read(file,me) )
	return notify_fail("没有找到/log/jnlog.txt。\n");
    me->start_more(trans_color(read_file(file)));
    return 1;
}

int help(object me)
{
    write(@HELP
该命令可以查看巫师对MUD的武功修改调整记录。
HELP);
    return 1;
}
