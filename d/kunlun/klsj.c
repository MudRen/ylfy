
inherit ROOM;
void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sbxd",
]));
	set("����ɽ��", "short");

	setup();
	replace_program(ROOM);
}
