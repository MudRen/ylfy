// Room: /d/cxwxm/feifeng3.c
// marry 8,14
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"后花园"NOR);
        set("long", 
"这里是飞凤轩的小花园，里面种满了白色的茉莉花，但定睛细\n"
"看也不尽相同。看来此间的主人对茉莉甚是喜爱，将各地的白茉莉\n"
"收集到这儿。再往花丛中望去有几个小姑娘似乎正在采花。\n\n"
);
        set("outdoors","cxwxm");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"feifeng2",
]));
        set("objects",([
                "/d/cxwxm/npc/yahuan":2,
        ]));


        setup();
        replace_program(ROOM);
}
