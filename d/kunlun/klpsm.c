// Room: /d/kunlun/klpsm.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������ɽ��");
	set("long", @LONG
������ǰ��һ����ɫ�����ɽ��, ���������ɷ���ıʼ���д���������ɡ�
���֣���˵�������ɿ�ɽ��ʦ������ױ����⡣����������ȥ��һ���Ĵ�Ĺ�
������ǰ����һ����ʯ����Ľ�������ɽ�����϶��¡�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 4,
]));
	set("outdoors", "klpsm");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wft",
  "north" : __DIR__"bwc",
]));

	setup();
	replace_program(ROOM);
}
