// Room: /d/wudie/ydt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "艳蝶堂");
        set("long", @LONG
这里是琼雅蝶休息的地方，布置的非常雅致，窗边放一张书桌，桌
上摆满了秘籍，一张楠木床，床边有一张梳妆台，墙上挂着一把古色古
香的宝剑。不时还有彩碟飞进飞出。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wdt",
  "north" : __DIR__"rht",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
