// Room: /d/cxwxm/changlang.c
// marry 8,14

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"长廊"NOR);
        set("long",
"这是一条非常精美的长廊，柱子和栏杆是用华贵的汉白玉制成，上面\n"
"用琉璃瓦镶嵌着美丽的图画。地板则仍是用天然的大理石铺成。在这里走\n"
"过的人仿佛置身于宫廷之中。\n\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dayuan",
  "west" : __DIR__"changlang2",
]));

        setup();
        replace_program(ROOM);
}

