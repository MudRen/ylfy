#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{	
       set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong87",
		"west" : __DIR__"dong12",
                	]));
         set("objects", ([
               __DIR__"npc/lev" : 1,
              __DIR__"npc/lev" : 1,
              "/clone/box/gbox" : random(2),
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
