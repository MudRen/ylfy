// Room: /d/heimuya/zhaoze/penquan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
һ���޴��ˮ����ʯ����ֱ�������������գ��ߴ�������࣬��ѩ
����ֻ��ˮ����̫����ҫ��ӳ��һ��ѣĿ�����Ĳʺ硣��������������
�ٰ�����֮�⣬ȴҲ��֪˵��ô���á�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shanbian",
  "west" : __DIR__"shandian",
]));
	set("outdoors", "penquan");

	setup();
	replace_program(ROOM);
}
