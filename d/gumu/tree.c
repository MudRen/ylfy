
#include <ansi.h> 
inherit ROOM;

void create()
{
     set("short", HIY"树上"NOR);
     set("long", @LONG 

这里是树上，你突然发现树叶中有些动静，哇。。。。。。!!!
LONG
);
     set("outdoors","古墓");

     set("exits", ([ 
     "down" : __DIR__"xuanya",
         ]));

             setup();
        replace_program(ROOM);       

} 

