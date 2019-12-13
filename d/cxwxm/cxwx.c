// Room: /d/cxwxm/cxwx.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"大门前"NOR);
        set("long",
"你抬头一望，只见大门上挂着一个牌匾，上曰："+HIG"【痴心妄想门】"NOR+"。门前\n"
"站着的两个年轻人正微笑着这看着你。\n\n"
);
        set("outdoors","cxwxm");
        set("exits", ([ /* sizeof() == 1 */
              "east" : __DIR__ "damen.c",
              "south" : __DIR__ "tianye",
        ]));
        set("objects",([
                "/d/cxwxm/npc/dizi":2,
        ]));

        setup();
        replace_program(ROOM);
}
