// riyueyan.c ������ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"" : __DIR__"",
		"" : __DIR__"",
             "": __DIR__"" 
	]));
	setup();
	replace_program(ROOM);
}



