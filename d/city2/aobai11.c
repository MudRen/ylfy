
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "东厂暗道");
	set("long", @LONG
这是一条暗道，是专为鳌拜从鳌府直接到东厂用的。
LONG
	);
	set("exits", ([
		"southwest" :  __DIR__"aobai10",
		"northeast" : __DIR__"aobai12",
	]));
	setup();
	replace_program(ROOM);
}
