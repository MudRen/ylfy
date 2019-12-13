// Room: caodi1.c

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
这是一片郁郁葱葱的青草地，四周云雾缭绕的青山。草丛中夹杂
着一些白色的野花，象洒落的珍珠一般。时而传来些许小虫的轻鸣。东
北面的山脚有一棵参天的古树，树荫下看起来非常的凉爽。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qingcaodi",
  "west" : __DIR__"caodi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

