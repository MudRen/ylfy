// Room: /d/kunlun/wft.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����Ľ���Ҳ�ս����˾�ͷ, ���ݵľ�ͷ������һ��ɽ��, ɽ�������ɷ�
���д��������, �����Ծ������Ե����ƷǷ���ɽ�紵������˿˿�ĺ���, ��
���йɸߴ���ʤ���ĸо���
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 2,
]));
	set("outdoors", "wft");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhp",
  "south" : __DIR__"zwf",
  "north" : __DIR__"klpsm",
  "west" : __DIR__"ssy",
]));

	setup();
	replace_program(ROOM);
}
