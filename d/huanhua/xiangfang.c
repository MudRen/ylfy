//xiangfang.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�����Ǽ䲻��ķ��ӡ���ǽ����һ��̴ľ������������������Ŀ���ǽ
�ߣ�����ĳ���������Կ����ľ�������СԺ������ɽ���ӹ���Ʈ����
����Ҷ�����㡣
LONG
	);

	set("exits", ([
                "east" : __DIR__"dating",
		]));
	set("objects", ([
		  __DIR__"npc/xiaoqiushui" : 1,
	]));

	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
