// Room: /d/wudie/pxt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "飘香园");
        set("long", @LONG
刚一进园，一股很特别的香气扑面而来，不由深深的吸了一口，浑
身的疲劳和饥饿完全消失了。园正中是一个池塘，池塘里盛开着几朵硕
大的白花，原来香气正是这白花所放。向前一看，你惊呆了，前面居然
有一片彩色的云在动，你情不自禁加快步伐......
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qjm",
  "north" : __DIR__"wdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
