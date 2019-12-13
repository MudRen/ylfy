
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "洞后"NOR);
    set("long", @LONG
你信步走到洞后，只见树木苍翠，山气清佳。北面是陡峭的石壁，
东北面有一条小路不知通到哪里去。
LONG
    );

    set("outdoors", "shengu");

    set("exits", ([
        "enter" : __DIR__"shandong",
        "north" : __DIR__"qiaobi",
 
    ]));

    setup();
    replace_program(ROOM);
}
