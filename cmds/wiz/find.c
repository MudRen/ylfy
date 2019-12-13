// find
#include <ansi.h>

int main(object me, string arg)
{
	string file, *list, file_name, str, old_msg;
	int i;

	if ( !arg ) return notify_fail("ָ���ʽ��find �ļ���,���ҵ��ִ�\n");
	if ( sscanf(arg, "%s,%s", file_name, str) != 2 ) return notify_fail("ָ���ʽ��find �ļ���,���ҵ��ִ�\n");
	if ( file_size(file_name) < 1 ) return notify_fail("û������ļ�("+arg+")��\n");

	file = read_file(file_name);
	if ( strsrch(file, "\n") == -1 ) return notify_fail("�ļ�("+arg+")ֻ��һ�С�\n");
	list = explode(file, "\n");
	for ( i = 0; i < sizeof(list); i++ )
	{
		old_msg = replace_string(list[i], list[i], lower_case(list[i]));
		if ( sscanf(old_msg, "%*s"+lower_case(str)+"%*s") )
		{
			list[i] = replace_string(list[i], str, HIY+str+HIW);
			if ( i > 0 )
				write("��"HIY+i+NOR"�У�"NOR+list[i-1]+"\n"NOR);
			write(HIG"��"HIY+(i+1)+HIG"�У�"HIW+list[i]+"\n"NOR);
			if ( i < sizeof(list) - 1 )
				write("��"HIY+(i+2)+NOR"�У�"NOR+list[i+1]+"\n"NOR);
			write("----------------------------------------------------------------------\n");
		}
	}

	return 1;
}