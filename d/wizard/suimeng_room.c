
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "suimeng �칫��");
	set("long", YEL@LONG
�������suimeng�İ칫��,��ȻС�˵㣬����ȴ���õþ�������.
�糿������͸�������Ĳ����������ڴ��ߵİ칫���ϣ���ʱ��
��ֻС��ߴߴ�����ĴӴ�ǰ�ɹ����򿪴�����һ�����µ�����
��Ϣ�����峿С�ݵķ����������, �µ�һ���ֿ�ʼ�ˡ�����
ǽ�Ϲ���һ��װ�(board)����������¼�ճ��������ŵġ�
LONG NOR );

	set("exits", ([ /* sizeof() == 1 */
         "east" : __DIR__"wizard_room",
          "south" : __DIR__"newsroom",          
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
	
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
	{
		if( dir=="down" && !wizardp(me) )
			return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
		return ::valid_leave(me, dir);
	}
