// Room: /d/wudie/shanlu15.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
山间小路曲径通幽，雀鸣花响好不自在。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanlu16",
  "southdown" : __DIR__"shanlu14",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
