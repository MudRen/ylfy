// Room: /d/wudie/shanlu18.c
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
  "northup" : __DIR__"shanlu20",
  "southeast" : __DIR__"shanlu17",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
