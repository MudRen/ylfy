// Room: shanlu4.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条幽静的小山路，不知通向何处，只有那随风摇曳的路边青草，
一摇一摆，象是给你指点方向。草上一颗颗露珠，晶莹透亮，闪闪发光。周
围万籁俱静，只有你那脚步声，沙沙作响。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neitang",
  "north" : __DIR__"shanlu3",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

