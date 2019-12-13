// Room: /d/wudie/shanlu2.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
小路上人烟很少，周围景色秀美，犹如人间仙景。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shanlu",
  "northwest" : __DIR__"shanlu3",
    "southdown" : __DIR__"shanlu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
