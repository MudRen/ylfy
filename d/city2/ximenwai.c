// Room: /d/city2/ximenwai.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ı���������·�Ͽ������������ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/gaochang/room1",
  "east" : __DIR__"ximen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
