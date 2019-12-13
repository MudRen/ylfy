// Room: /d/city2/di_an1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "地安门东大街");
	set("long", @LONG
这是一条东西走向的大道。西边通往地安门。东边通往王府井。
南边就是东厂了，一般人都不敢往那儿去。
LONG
	);
	set("outdoors", "city2");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"di_an2",
  "south" : __DIR__"dongchangdamen",
  "east" : __DIR__"wangfu3",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/drunk" : 1,
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
