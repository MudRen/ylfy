// Room: /d/gaochang/room61.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "昆仑山");
	set("long", @LONG
这座松林好长，走了半个时辰方始过完，一出松林，只见眼前满峰是雪，使
人更觉惊心动魄。银色的月光映著银色的雪，身当此境，不禁也生栗栗之感，顿
觉大千无限，一己渺小异常。
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "room61");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang" : 3,
]));
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"room62",
  "south" : __DIR__"room64",
  "east" : __DIR__"room60",
]));

	setup();
	replace_program(ROOM);
}
