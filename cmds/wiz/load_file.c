inherit F_SKILL_OB;

int help(object me);

int main(object me, string arg)
{
	if ( !arg )
		return notify_fail("��Ҫ�����ĸ��ļ���\n");

	if ( arg[0..0] != "/" )
		arg = "/" + arg;

	if ( arg[(sizeof(arg)-1)..(sizeof(arg)-1)] == "/" )
	{
		load_skill_ob(arg);
		return 1;
	}

	if ( file_size("/binaries" + arg + ".b") > 0 )
	{
		if ( !find_object(arg) )
		{
			if ( load_object(arg) )
			{
				write("�ɹ������ļ� " + arg + " ��\n");
				return 1;
			}
			else
				return 0;
		}
		else
			return notify_fail("����ʧ�ܣ��ļ� " + arg +" �Ѵ������ڴ档\n");
	}
	else
		return notify_fail(arg + " �Ķ������ļ������ڡ�\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : load_file string
�����ļ��ļ���[string]��
string ���һ���ַ�Ϊ '/' ʱ��Ϊ����Ŀ¼��
HELP
);
	return 1;
}