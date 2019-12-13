// road1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
大道上挤满了来灵隐寺上香和上飞来峰的游客。北边过了小溪就
是灵隐寺了。南边是上飞来峰的路。
LONG);
        set("exits", ([
                "northwest" : "/d/jiaxing/jxnanmen",
                //"east" : "/d/jiaxing/jnroad2",
                "west" : "/d/nanchang/guandao5",
                "northeast" : __DIR__"road2",
                "north"     : __DIR__"lingyinsi",
                "south"     : __DIR__"feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
