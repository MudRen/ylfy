//changlang2.c

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
                "east" : __DIR__"changlang",
            "south" : __DIR__"shanshiting",
                "west" : __DIR__"changlang3",
                ]));

        set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
