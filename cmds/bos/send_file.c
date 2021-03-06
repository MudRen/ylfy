// send_file

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string ader, msg, file, pass;

	if ( !interactive(me) )
		return 0;

	seteuid(getuid());

	if ( !arg )
		return notify_fail("你要连接哪里？\n");

	if ( sscanf(arg, "%s@%s#%s", ader, file, pass) != 3 )
		return notify_fail("指令格式：send_file Ip Port@File#Passwd？\n");

	if ( file_size(file) < 0 )
		return notify_fail("你要发送的文件不存在。\n");

	msg = file + "#" + pass;
	FILESERVER->connect_to(ader, msg);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: send_file Ip Port@File#pass

这个指令可以让你向远端服务器(ip port)传送文件(File)

HELP );
        return 1;
}
