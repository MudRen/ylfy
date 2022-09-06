// Room: /d/heimuya/zhaoze/lingding.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "岭顶");
	set("long", @LONG
空山寂寂，那水声在山谷间激荡回响，轰轰汹汹，愈走水声愈大，待
得走上岭顶，只见一道白龙似的大瀑布从对面双峰之间奔腾而下，声势甚
是惊人。从岭上望下去，瀑布旁有一间草屋。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"pubupang",
  "southdown" : __DIR__"pubu",
]));
	set("outdoors", "lingding");

	setup();
	replace_program(ROOM);
}
