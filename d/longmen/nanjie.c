
inherit ROOM;
void create()
{
        set("short", "小镇南街");
        set("long", @LONG
走到这里，突然一阵马嘶声从东面的一个房子里传来，原来东面是
一家驿站，西面房子伸出一个竹竿，上面挂着一个条幅。只一个字：“
当”，看来是一家当铺。
LONG );
        set("valid_startroom",1);
        set("outdoors","龙门");
        set("class","血河派");
        set("exits", ([
                "south"  : __DIR__"sexit",
                "north"  : __DIR__"sqare",
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


