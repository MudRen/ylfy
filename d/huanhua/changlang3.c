//changlang3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������ĳ��ȣ�����û��ʲô����⻬��ʯ��������һЩ��Ȼ��
����ʱ����һЩ佻����ִҴ��߹�������ͨ��佻����ɵ����á�
LONG
        );

        set("exits", ([
                "east" : __DIR__"changlang2",
             "north" : __DIR__"lianwuchang",
                "west" : __DIR__"zhenmei",
                ]));

        set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
