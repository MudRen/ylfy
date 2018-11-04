#include <room.h>
inherit ROOM;

void create()
{
        set("short", "瀑布边");
        set("long", @LONG
你好不容易才爬上了这个悬崖，不由得长舒一口气。哗啦啦的水声从
西边传来，原来你已经到了龙门瀑布旁边。当年卫悲回就是在这与萧秋水
一战的，想到这里，你不由得加快脚步，想从一代奇人当年来过的地方找
到什么值得纪念的东西。
LONG);
        set("valid_startroom",1);
        set("exits", ([
		"southdown" : __DIR__"shugan3",
		"west" : __DIR__"pubu",
        ]));
        set("outdoors","龙门");
        setup();
        replace_program(ROOM);
}

