
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "殿堂");
    set("long", @LONG
走到大殿之后，见是一座较小的殿堂，殿中情景却尤为可怖，数十具骸骨一
堆堆相互纠结，骸骨大都直立如生时，有的手中握有兵刃，有的却是空手。
    西侧有一扇小石门。
LONG
    );
        set("objects", ([ 
  __DIR__"obj/skeleton" : 10,
]));
    set("exits", ([ 
       "south" : __DIR__"room36",
        "west" : __DIR__"room38",
    ]));
    create_door("west", "小石门", "east", DOOR_CLOSED);
    setup();
}
