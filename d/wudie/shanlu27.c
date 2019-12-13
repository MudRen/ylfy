// Room: /d/wudie/shanlu27.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
慢慢陡峭起来，举头隐见云间山峰。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu28",
  "southeast" : __DIR__"shanlu26",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
