//      chang.c ���䳡
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","���䳡");
        set("long",@LONG
������ѩɽ�����䳡��ɮ�����ڴ�ϰ�䡣
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
        ]));
set("objects", ([
CLASS_D("xueshan")+"/gelunbu" :1,
        __DIR__"npc/x_lama" : 1 ,
]));
        setup();
        replace_program(ROOM);
}

