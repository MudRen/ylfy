// nroad7.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
������һɽ·�ϣ�������һ����Сɽ��
LONG );
        set("exits",([
                "eastdown" : "/d/xueshan/shanjiao",
                "south"    : __DIR__"nroad6",
        ]));
        set("objects",([
"/d/xuedao/npc/shanyong" : 1,	
        ]));
        set("outdoors", "xueshan");
        set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

