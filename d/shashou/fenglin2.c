// fenglin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������䣬����һ�����ķ�죬�����Ѫ�˰�ȽȽɢ����
ÿƬ��Ҷ���ʺ����Σ���þ�����һ��Ѫ�ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
             "east" : __DIR__"fenglin1",
"west" : __DIR__"xiaochidian",	
	]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
