// shanlu10.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
那悬崖下临深谷，上面山峰笔立，峰顶深入云雾之中，不知尽头。 “断
肠崖”前后风景清幽，只因地势实在太险，山石滑溜溜，极易掉入深渊，人们
轻易不敢来此。
LONG
     );

    set("exits", ([ 
                "westdown"  : __DIR__"shanlu9",
                "eastup"  : __DIR__"duanchang",                         
    ]));

    set("outdoors", "古墓");

    setup();
}

