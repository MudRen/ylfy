
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条被人走出来的小山路，虽然不宽却是够一辆马车通行。小路
顺着山中较为平坦地带缓缓向西伸展。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room51",
  "eastup" : __DIR__"room3",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room4");

	setup();
	replace_program(ROOM);
}
