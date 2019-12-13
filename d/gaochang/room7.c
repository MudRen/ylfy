
inherit ROOM;
void create()
{
	set("short", "沙砾小径");
	set("long", @LONG
这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地气极干
燥，连风都是暖的。地上的石砾发出一种暗红的颜色，就象是被鲜血染红的
一样。一条布满车痕的小径向西方和东方伸展。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room8",
  "eastup" : __DIR__"room6",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room7");

	setup();
	replace_program(ROOM);
}
