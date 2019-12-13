#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","岸边");
         set("long",@long
从小舟下来，你踏上了小岛的岸边，只见三面全是花的世界。落第秀才，
十八学士，十三太保，八仙过海，风尘三侠等数种名贵的茶花萦绕在你的
周围，你已经身陷花丛中，如果不仔细的辨别方向，很难能够走出去。
long);
         set("outdoors","mr");
/*       set("objects",([
             __DIR__"npc/youcao" : 1,
]));
*/       set("exits",([
             "south" : __DIR__"hc",
             "east" : __DIR__"hc1",
             "west" : __DIR__"hc2",
]));
         setup();
         replace_program(ROOM);
}
