
inherit ROOM;

void create()
{
	set("short", "���׽���");
	set("long", @LONG
������ʮ����ż���һ��С�������ڼ��˹����������ţ�ֻ���ű�ʯ��
���š����˶ɡ��������֡�
LONG
);
	set("outdoors", "lczb1");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tsq",
  "north" : __DIR__"lczb",
]));

	setup();
	replace_program(ROOM);
}
