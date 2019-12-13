// Room: /d/wudie/pjt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "飘锦园");
        set("long", @LONG
这里种满了珍贵的药材，不知从哪搜罗了这么多？有千年何首乌，
长白山老人参。更让人不可思议的是在园子的一个角落里，有一堆雪终
年不化，雪中开着几朵白花，这就是武林人士梦寐以求的天山雪莲。还
有许许多多的药材。真是数不胜数。
LONG
);
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"rht",
  "south" : __DIR__"wdt",
  "west" : __DIR__"dyt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
