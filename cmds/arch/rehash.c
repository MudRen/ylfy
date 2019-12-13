// rehash.c
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	if ( !arg ) return help(me);
	if ( arg[strlen(arg)-1]=='/' ) arg =arg[0..(strlen(arg)-2)];
	if ( file_size(arg)!=-2 && file_size("/binaries"+arg)!=-2) 
		return notify_fail("û�����Ŀ¼��\n");
	
	write("����ָ���" + arg + "\n");
	COMMAND_D->rehash_b(arg);
	COMMAND_D->rehash(arg);
	write("OK!\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��rehash <Ŀ¼����>
���ָ������ϵͳ�ڲ���ָ��������������ɾ����ĳ��Ŀ¼�µ�ָ�������
���ָ����¸�Ŀ¼����ʹ�á�
HELP
	);
	return 1;
}
