//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","斋房");
	set("long", @LONG

这里是蜀山剑派的斋房,东西面是西小路，看起来这里有很
多好吃的。大厨子的手艺看起来很不错啊。你可以要些(yao)
吃的。
LONG);
        
       set("no_fight",1);
       set("exits", ([
	  "east" : __DIR__"westway2",
	]));

        set("objects", ([         
        __DIR__"npc/chuzi" : 1,
        "/clone/food/jiudai" :1,
        ]));
       set("clean_up", 1);
       set("resource", ([        
       "water" : 1,
       ]));
      setup();
}
int valid_leave(object me, string dir)
{
       if((present("gongbao jiding", this_player())))
            return notify_fail("吃完包子再走吗！\n");
            if((present("hulu", this_player())))
            return notify_fail("你不能把酒袋带走！\n");
             return ::valid_leave();
}


