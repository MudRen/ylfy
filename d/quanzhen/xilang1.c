//xilang1.c 西厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
你走在一条长长的走廊上。房顶一侧支在北面的八仙殿上，另一侧则
与东边三清殿的屋顶相连。走廊二边的墙上刻着的是老子的《道德经》，
往北是八仙殿。
LONG
	);

	set("exits", ([
	      "north" : __DIR__"baxiandian",
             "east" : __DIR__"sanqingdian",
	]));
	setup();
	replace_program(ROOM);
}
