inherit ROOM;
void create()
{
	set("short", "星星峡");
	set("long", @LONG
峡内两旁石壁峨然笔立，有如用刀削成，抬头望天，只觉天色又蓝又亮，宛
如潜在海底仰望一般。峡内岩石全是深黑色，显得乌光发亮。道路弯来弯去，曲
折异常。峡内初有积雪，黑白相映，蔚为奇观。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room5",
  "east" : __DIR__"room51",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room52");

	setup();
	replace_program(ROOM);
}
