// Room: /d/changan/ca34.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ������Ǵ�С
��������������ֱ�ﳤ���ǡ�
LONG
);
	set("no_clean_up", 0);
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ta2",
  "northwest" : __DIR__"ca13",
  "south" : "/d/city3/xiaolu1",
  "east" : __DIR__"ta1",
]));

	setup();
	replace_program(ROOM);
}
