// Room: /d/huashan/liangong1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǻ�ɽ�����������ĵط���������ʲôҲû�С�
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"bingqifang",
  "north" : __DIR__"liangong2",
  "south" : __DIR__"liangong3",
]));

	setup();
	replace_program(ROOM);
}
