#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"石洞"NOR);
	set("long", CYN @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong47",
		"west" : __DIR__"dong17",
                	]));
       set("objects", ([
               __DIR__"npc/lev" : 1,
              __DIR__"npc/lev" : 1,
                ]));
	set("no_clean_up", 0);
        set("objects", ([
               __DIR__"npc/lev" : 1,
              __DIR__"npc/lev" : 1,
                ]));
	setup();
	replace_program(ROOM);
}
