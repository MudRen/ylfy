// Room: /d/wudie/shanlu35.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
远远的你已经可以看见山顶的舞蝶山庄，山庄彩云琼绕。
朵朵彩云在围绕在山庄周围看来那里是遥不可及的仙境。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu34",
  "northup" : __DIR__"shanlu36",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
