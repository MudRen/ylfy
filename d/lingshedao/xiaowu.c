//Room:/d/lingshedao/xiaowu.c
inherit ROOM;
void create()
{
        set("short", "小茅屋");
        set("long", @LONG
屋里昏昏暗暗的,居然连盏油灯也没有.屋里的陈设
也非常简陋,只有一桌,一椅,一床而已.
LONG );
        set("exits", ([
                "out"    : __DIR__"xiaowuout",
        ]));
        set("objects",([
                __DIR__"npc/xiexun" : 1,
        ]));
        //set("no_clean_up",0);
//        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
