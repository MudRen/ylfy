
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIY"日月岩"NOR);
     set("long", @LONG
此去道路陡然险峻，乱石悬崖，屈曲而上。高处森然腾越出两石，遥相呼
应，一石浑圆仿如天日，一石曲弯恍若新月。正是日月岩所在。
LONG        );

     set("outdoors","古墓");

     set("exits", ([
         "northdown" : __DIR__"jlg",
         "westup" : __DIR__"bzy",
       ]));
        set("objects", ([
                "/d/wugongzhen/npc/youke" : 2, 
   ]));
     setup();
}

