// player.c
#include <ansi.h>
inherit ROOM;
 
void create()
{
	
	set("exits", ([
		"out" : "/d/taohuacun/taohua5",
	]));
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

