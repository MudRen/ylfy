// Room: /d/cxwxm/dayuan.c
// marry 8,14
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIC"大院"NOR);
        set("long", 
"这里是痴心妄想门的大院，和一般的豪宅大院没太大的\n"
"区别，大理石的地板，不知名的红砖墙。几个仆人正在打扫\n"
"院内的落叶。大院东西南北都有出口，而在东南方向好象是\n"
"一个花园。\n\n"
);
        set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"xiuxishi",
  "southeast" : __DIR__"huayuan",
  "east" : __DIR__"houmen",
  "north" : __DIR__"dating",
  "west" : __DIR__"changlang3",
]));
        set("objects",([
                "/d/cxwxm/npc/puren":4,
        ]));

        setup();
        replace_program(ROOM);
}

