// Room: /d/dali/duan4.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��7�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ�Ե����ȣ�������һ��Ļ��������ڳ��軪��������
������������˼��������ΰ�����ĵ����ֱ���һ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"duan5",
  "north" : __DIR__"duan3",
]));

set("objects", ([
__DIR__"npc/yahuan" : 2,
]));
	setup();
}

