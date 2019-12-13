
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write( "指令格式： memclear <档案名>" + 
		"这个指令让你清理一些占用内存的物件(一般都是由BUG引起的)。" + 
		"注意：只能由高级巫师使用，并且，慎用！\n");
	
	return 1;
}

private void confirm_clear( string inp, object *objs );

int main( object me, string arg )
{
	object *objs;
	
	if( me != this_player(1) && wizhood(me) != "(boss)" )
		return 0;
	
	if( !arg )
		return help(me);
	
	seteuid( getuid(me) );
	objs = children( arg );
	
	if( !sizeof( objs ) )
		return notify_fail("未发现任何此文件名的复制件：" + arg + "\n");
	
	write(HIW"发现 "HIY+sizeof( objs )+HIW" 个此文件名的复制件。\n"+ HIY"你确定要将无环境( !environment() )的部分都清除吗？(y/n)"NOR );
	
	input_to( "confirm_clear", objs );
	
	return 1;
}

private void confirm_clear( string inp, object *objs )
{
	object ob;
	int i, j;
	
	if( inp != "y" && inp != "Y" )
	{
		write("好的，放弃清除操作。\n");
		return;
    }
	
	foreach( ob in objs )
	{
		i ++;
		
		if( !environment( ob ) )
		{
			destruct( ob );
			j ++;
		}
	}
	
	write(HIW"总共有 "HIG + i + HIW" 个物件，清理了 "HIR + j + HIW" 个无环境( !environment() ) 的物件。\n");
	
	return;
}