//xilang3.c 西厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
	你走在一条长廊上，东边是后殿，西边是练功房。
LONG
	);

	set("exits", ([
	     "west" : __DIR__"liangongfang",
           "east" : __DIR__"houdian",
          ]));
	setup();
	replace_program(ROOM);
}
