
#include <ansi.h>
inherit F_CLEAN_UP;

string memory_expression(int m);
private varargs void check_mem( string file );
private void check_memory_info();

int main(object me, string arg)
{
	object obj;
	string file;
	
	if( me != this_player(1) || !wizardp(me) )
		return 0;
	
	if ( !arg )
	{
		check_memory_info();
		return 1;
	}
	
	if( arg == "-m" )
	{
		write(malloc_status()+"\n");
		return 1;
	}
	
	if( arg == "-all" )
	{
        if( wizhood(me) != "(boss)" )
            return notify_fail("���ָ�����ֻ���ɸ߼���ʦʹ�á�\n");
		
		check_mem();
		
		return 1;
	}
	
	if( sscanf( arg, "-all %s", file) == 1 )
	{
		check_mem(file);
		return 1;
	}
	
	seteuid(geteuid(me));
	obj = find_object(arg);
	
	if ( !obj || !me->visible(obj) )
		obj = present(arg, me);
	
	if ( !obj || !me->visible(obj) )
		obj = present(arg, environment(me));
	
	if ( !obj || !me->visible(obj) )
		obj = find_object( resolve_path(me->query("cwd"), arg) );
    
	if ( !obj || !me->visible(obj) )
		return notify_fail(HIY"�޷�ͨ�� find_object() �ҵ������������Я�������������������Ҳû���ҵ����������\n");
	
	printf( "%O ��ʹ�� %s bytes �����塣\n", obj, memory_expression(memory_info(obj)));
	return 1;
}

string memory_expression(int m)
{
	float mem;
	
	mem = m;
	
	if( mem<1024 )
		return m + "  ";
	
	if( mem<1024*1024 )
		return sprintf("%.2f K",(float)mem / 1024);
	
	return sprintf("%.3f M", (float)mem / (1024*1024));
}

private void check_memory_info()
{
    write( sprintf( "[%s]Ŀǰ��ʹ�� %s bytes �����塣\n", MUD_NAME, memory_expression(memory_info()) ) );
}

private varargs void check_mem( string file )
{
	object me = this_player();
	object *objs;
	mixed groups;
	int i, j, size, tmp_mem, all_mem, shout_msg;
	string msg = "", tmp_msg;
	
	if( file )
	{
		if( file[<2..<1] == ".c" )
			file = file[0..<3];
		
		objs = children( file +".c" );
		
		if( !sizeof( objs ) )
		{
			write( "δ�����κα��ļ������ļ���"+ file +"\n");
			return;
		}
		else
			groups = unique_array( objs, (: base_name( $1 ) : ) );
	}
	else
	{
		shout_msg = 1;
		objs = objects();
		groups = unique_array( objs, (: base_name( $1 ) :) );
	}
	
	if( shout_msg )
	{
		message("channel:jh", HIR"��ϵͳ���顿"+HIW"���ڼ�����ݣ���Ϸ���ܻ��������ͣ������ĵȴ�.....\n"NOR,users() );
		tell_object(me,"\n"HIW"["HIY + MUD_NAME+ HIW"]"HIW"���ݼ�⣺" );
	}
	
	write(sprintf( "�������� "HIG"%d"HIW" ���ļ����ɵ� "HIY"%d"HIW" ������������\n"NOR, sizeof( groups ), sizeof( objs ),  ) );
	write(HIW"["HIY + MUD_NAME + HIW"]"HIG"�ڴ�ռ����ϸ�б����£�\n"NOR );
	msg += sprintf(HIY"%-45s%-9s%-9s%-8s"HIW"/"HIY"%-8s\n"NOR,
		"��    ��    ��",
		"��������",
		"ռ���ܶ�",
		"��һռ��",
		"ƽ��ռ��");
	
	for( i=sizeof(groups)-1; i>=0; i-- )
	{
		tmp_mem = 0;
		size = sizeof( groups[i] );
		for( j=size-1; j>=0; j-- )
		{
			tmp_mem += memory_info( groups[i][j] );
		}
		all_mem += tmp_mem;
		tmp_msg = sprintf( "%12s", memory_expression( tmp_mem ) );
		tmp_msg = replace_string( tmp_msg, "K", HIC"K"NOR );
		tmp_msg = replace_string( tmp_msg, "M", HIR"M"NOR );
		msg += sprintf( "%-45s%-3d"HIY"��"NOR"%8s %8s"HIW"/"NOR"%-8s\n",
			base_name( groups[i][0] ), size, tmp_msg,
			size != 1 ? memory_expression( memory_info(groups[i][0]) ) : "--",
			size != 1 ? memory_expression( tmp_mem / size ) : "--",);
	}
	
	me->start_more( msg );
	
	write( HIW"\n\n���Ϻϼ�ʹ���ڴ棺"HIG + memory_expression( all_mem ) +  HIW"," + HIW"ʵ��ʹ��:"HIY);

	check_memory_info();
	
	if( shout_msg )
	{
		message("channel:jh", HIR"��ϵͳ���顿"+HIW"���ݼ����ϡ�\n"NOR,users() );
		tell_object(me,HIW"["HIY + MUD_NAME+ HIW"]"HIW"���ݼ����ϡ�\n" );
	}
}

int help(object me)
{
    write(@HELP
ָ���ʽ : mem [-all] [�����(id)���ļ���]

���ָ������鿴����վ��(��ĳ���)ռ�õ��ڴ���Ϣ��

�Ӳ��� -all ʱ��
    �������������ʱ��������ʾ����վ��������������ڴ�ռ����Ϣ��
    �����������ʱ����ʾ����������и����������ڴ�ռ����Ϣ��

���Ӳ��� -all ʱ��
    �����������������ʾ MUD Ŀǰռ�õ��ڴ�������
    ���������������ʾ�����ռ�õ��ڴ�����
HELP
    );
    return 1;
}
