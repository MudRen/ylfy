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
		return notify_fail("��Ҫ�������\n");

	if ( sscanf(arg, "%s@%s#%s", ader, file, pass) != 3 )
		return notify_fail("ָ���ʽ��send_file Ip Port@File#Passwd��\n");

	if ( file_size(file) < 0 )
		return notify_fail("��Ҫ���͵��ļ������ڡ�\n");

	msg = file + "#" + pass;
	FILESERVER->connect_to(ader, msg);
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
