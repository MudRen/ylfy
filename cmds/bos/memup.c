
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
            return notify_fail("这个指令参数只能由高级巫师使用。\n");
		
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
		return notify_fail(HIY"无法通过 find_object() 找到这样物件、你携带物件、你所处环境中也没有找到这样物件。\n");
	
	printf( "%O 共使用 %s bytes 记忆体。\n", obj, memory_expression(memory_info(obj)));
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
    write( sprintf( "[%s]目前共使用 %s bytes 记忆体。\n", MUD_NAME, memory_expression(memory_info()) ) );
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
			write( "未发现任何本文件名的文件："+ file +"\n");
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
		message("channel:jh", HIR"【系统精灵】"+HIW"正在检测数据，游戏可能会有所迟滞，请耐心等待.....\n"NOR,users() );
		tell_object(me,"\n"HIW"["HIY + MUD_NAME+ HIW"]"HIW"数据检测：" );
	}
	
	write(sprintf( "共发现由 "HIG"%d"HIW" 个文件生成的 "HIY"%d"HIW" 个载入的物件。\n"NOR, sizeof( groups ), sizeof( objs ),  ) );
	write(HIW"["HIY + MUD_NAME + HIW"]"HIG"内存占用详细列表如下：\n"NOR );
	msg += sprintf(HIY"%-45s%-9s%-9s%-8s"HIW"/"HIY"%-8s\n"NOR,
		"文    件    名",
		"复件数量",
		"占用总额",
		"单一占用",
		"平均占用");
	
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
		msg += sprintf( "%-45s%-3d"HIY"件"NOR"%8s %8s"HIW"/"NOR"%-8s\n",
			base_name( groups[i][0] ), size, tmp_msg,
			size != 1 ? memory_expression( memory_info(groups[i][0]) ) : "--",
			size != 1 ? memory_expression( tmp_mem / size ) : "--",);
	}
	
	me->start_more( msg );
	
	write( HIW"\n\n以上合计使用内存："HIG + memory_expression( all_mem ) +  HIW"," + HIW"实际使用:"HIY);

	check_memory_info();
	
	if( shout_msg )
	{
		message("channel:jh", HIR"【系统精灵】"+HIW"数据检测完毕。\n"NOR,users() );
		tell_object(me,HIW"["HIY + MUD_NAME+ HIW"]"HIW"数据检测完毕。\n" );
	}
}

int help(object me)
{
    write(@HELP
指令格式 : mem [-all] [物件名(id)或文件名]

这个指令让你查看整个站点(或某物件)占用的内存信息。

加参数 -all 时：
    不加物件名参数时，分类显示整个站点已载入物件的内存占用信息；
    加物件名参数时，显示该物件的所有复制体所的内存占用信息。

不加参数 -all 时：
    不加物件名参数，显示 MUD 目前占用的内存总量；
    加物件名参数，显示该物件占用的内存量。
HELP
    );
    return 1;
}
