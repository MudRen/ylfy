// send_file

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	
	if ( !interactive(me) )
		return 0;

	seteuid(getuid());

	if ( !arg )
		return notify_fail("��Ҫ�������\n");

	//if ( file_size(file) < 0 )
		//return notify_fail("��Ҫ���͵��ļ������ڡ�\n");

	"/adm/daemons/network/server_2000"->connect_to(me, arg);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: send_file Ip Port@File#pass

���ָ�����������Զ�˷�����(ip port)�����ļ�(File)

HELP );
        return 1;
}
