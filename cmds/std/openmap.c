// webuser.c


inherit F_CLEAN_UP;

int main( object me,string arg )
{
	if(!arg || arg != "None")
		arg = "";

	if( me->is_busy() )
		return notify_fail("�����һ��������δ��ɡ�\n");
	
	if( me->is_fighting() )
		return notify_fail("������ս���С�\n");

	if( me->query("temp_time_map") && arg == "None" )
		return notify_fail("��ļ�ʱ��ͼ�������ǹرյġ�\n");

	if( !me->query("temp_time_map") && arg != "None" )
		return notify_fail("��ļ�ʱ��ͼ�������Ǵ򿪵ġ�\n");
	
	if(arg == "None")
	{
		me->set("temp_time_map",1);
		write("��ر��˼�ʱ��ͼ���ܡ�\n");
	}
	else
	{
		me->delete("temp_time_map");
		write("����˼�ʱ��ͼ���ܡ�\n");
	}
	return 1;
}

int help( object me)
{
	write(@HELP
ָ���ʽ: openmap None|xxx
��ָ���������رջ�򿪼�ʱ��ͼ���ܡ�

HELP
	);
        return 1;
}
