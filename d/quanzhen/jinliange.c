// jinliange.c ������ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ�����
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"eastdown" : __DIR__"laoyuyan",
		"northup" : __DIR__"baoquan",
        ]));
	setup();
	replace_program(ROOM);
}



