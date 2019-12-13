// Room: /d/city/xidajie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "西大街");
	set("long", @LONG
	这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人
稀少，静悄悄地很是冷清。东边是一个热闹的广场。南边是兵营。北边就是衙门了。
LONG
	);
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xidajie2",
  "north" : __DIR__"yamen",
  "south" : __DIR__"bingyindamen",
  "east" : __DIR__"guangchang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/drunk" : 1,
]));
	setup();
	replace_program(ROOM);
}
