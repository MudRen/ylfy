//ROOM goldroom.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
        set("long",@LONG
����һ��С���ӣ����ϸɸɾ������˳���Ⱦ����ǽ�ǵĵط�����
�������ӣ���������������˴�����۵ĺ����յ�������ͬ����һ
�㡣
LONG
	);
        
	        
	set("exits", ([
		"east" : __DIR__"zongduo",
        ]));
	
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));	
	
	setup();
}