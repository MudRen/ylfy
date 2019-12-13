inherit ROOM;
void create()
{
	set("short", "昆仑山");
	set("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出昼
夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"room58",
  "eastdown" : __DIR__"room56",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room57");

	setup();
	replace_program(ROOM);
}
