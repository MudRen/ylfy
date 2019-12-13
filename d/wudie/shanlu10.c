// Room: /d/wudie/shanlu10.c
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
  "southwest" : __DIR__"shanlu9",
  "northwest" : __DIR__"shanlu11",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
