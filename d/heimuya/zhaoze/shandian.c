// Room: /d/heimuya/zhaoze/shandian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ�󣬹���������̲��һת�䣬��ǰ��ɫ�续����Ϫ������ˮ
��ƽ��֮�������ƶ�ס��������Ϫˮ��Լ�������Դ�����ˮ������֮��
��ֲ���������������ڴ����һ�ʢ��֮ʱ�������һƬ���壬����ҫ�ۡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"penquan",
  "northdown" : __DIR__"pubupang",
]));
	set("outdoors", "shandian");

	setup();
	replace_program(ROOM);
}
