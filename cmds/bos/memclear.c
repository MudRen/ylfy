
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write( "ָ���ʽ�� memclear <������>" + 
		"���ָ����������һЩռ���ڴ�����(һ�㶼����BUG�����)��" + 
		"ע�⣺ֻ���ɸ߼���ʦʹ�ã����ң����ã�\n");
	
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
		return notify_fail("δ�����κδ��ļ����ĸ��Ƽ���" + arg + "\n");
	
	write(HIW"���� "HIY+sizeof( objs )+HIW" �����ļ����ĸ��Ƽ���\n"+ HIY"��ȷ��Ҫ���޻���( !environment() )�Ĳ��ֶ������(y/n)"NOR );
	
	input_to( "confirm_clear", objs );
	
	return 1;
}

private void confirm_clear( string inp, object *objs )
{
	object ob;
	int i, j;
	
	if( inp != "y" && inp != "Y" )
	{
		write("�õģ��������������\n");
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
	
	write(HIW"�ܹ��� "HIG + i + HIW" ������������� "HIR + j + HIW" ���޻���( !environment() ) �������\n");
	
	return;
}