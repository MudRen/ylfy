// Room: /d/city2/road10.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小道");
	set("long", @LONG
你走在一条小道上。东边就是海港了.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/nanyang/ruzhou",
  "east" : __DIR__"haigang",
  "north" : __DIR__"road9",
  "west" : __DIR__"road1",
]));
	set("outdoors", "city2");
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  "/d/taishan/npc/tiao-fu" : 1,
]));
	setup();
	replace_program(ROOM);
}
