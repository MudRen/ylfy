// road.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������ͨ��ɱ��¥��һ��Сɽ·����������ȥ��ֻ
��һƬƬ���ķ��֡�������������ܾ����ĵģ���
�����߽���һ��������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"enterance",
		"north" : __DIR__"fenglin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
