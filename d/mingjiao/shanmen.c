// Room: shanmen.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","明教山门");
        set("long", @LONG
这就是明教的山门，朱红色的两根大柱子矗立在你的面前，
上面悬挂着一块黑色大匾，上书着“名扬五湖，威镇四海”几个
金色大字，甚是威严。江湖中明教的子弟众多，据说这座山门也
是一位出身富豪的明教子弟捐建的。
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mingjiaodizi" : 4,
  __DIR__"npc/xuda" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhandao",
  "south" : __DIR__"shanlu2",
]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

         if ((!myfam || myfam["family_name"] != "明教") && dir == "north" &&
                objectp(present("xu da", environment(me))))
           return notify_fail("徐达喝道：你不是明教弟子，不得入内。\n");
                
        return ::valid_leave(me, dir);
}
