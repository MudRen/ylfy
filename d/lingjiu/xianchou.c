// Room: /d/lingjiu/xianchou.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ɳ���");
	set("long", @LONG
����Ϳ쵽��翷�����ˣ�Խ�����ߣ�ɽ��Խ�ߣ�����������ߵİ�
��������Ũ������������ɽ��·������ɽ��û�߼�����������ǰ����һ��
ʯ�������顺�ɳ��š��������֣�������ɽ֮�����ɡ�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/mengpai/ljdizi" : 3,
]));
	set("outdoors", "lingjiu");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"jian",
  "eastup" : __DIR__"dadao1",
]));

	setup();
	replace_program(ROOM);
}
