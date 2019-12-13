// Room: shanpo2.c

inherit ROOM;

void create()
{
        set("short", "山坡");
        set("long", @LONG
小心翼翼地走完一段陡坡后，遥遥可以望见一个青翠的山谷，前
面的坡道也开始平坦起来。时时可以听到从山谷传来清脆的鸟鸣声。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanpo1",
  "north" : __DIR__"caodi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}



