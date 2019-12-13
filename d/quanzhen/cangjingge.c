// cangjingge.c 藏经阁

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
眼前一座小楼倚山而建,楼四周种满了奇花异草，几个道士持剑来回
走动，这里就是重阳宫要地之一的藏经阁。
LONG
	);

	set("exits", ([
		"west" : __DIR__"houyuan",
             "enter" :__DIR__"cangjingge1",	
          ]));

	setup();
	replace_program(ROOM);
}
