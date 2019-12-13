// Room: /d/wudie/shanlu40.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "山路尽头");
        set("long", @LONG
前面就是舞蝶仙境了。虚无的仙境近在眼前，你似乎都不敢相信。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu39",
  "northup" : __DIR__"jm",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
