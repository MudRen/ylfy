// Room: /d/kunlun/ssy.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "三圣坳");
	set("long", @LONG
这里长年人迹罕至。谷中古树参天，绿荫森森，白雪皑皑，简直让人疑心
自己到了世外桃源。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wft",
]));
	set("outdoors", "ssy");

	setup();
	replace_program(ROOM);
}
