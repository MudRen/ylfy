// xiangfang3.c �᷿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�����ǽ�����
LONG
	);
        
	set("exits", ([
		"" : __DIR__"",
		"" : __DIR__"",
        ]));
	setup();
	replace_program(ROOM);
}



