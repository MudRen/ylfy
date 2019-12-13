// Room: /d/cxwxm/gc.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "广场");
        set("long",
"这里是痴心妄想门的广场，整个广场由大块的大理石铺成，极\n"
"为豪华。但在这个广场中似乎莫名的安静，看不到一个弟子，却是\n"
"非常的干净。广场的东面是一个长廊，而在广场的南北方向各有一\n"
"间小屋。\n\n"
);
        set("outdoors", "cxwxm");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nanwu",
  "east" : __DIR__"changlang",
  "north" : __DIR__"beiwu",
  "west" : __DIR__"damen",
]));

        setup();
        replace_program(ROOM);
}
