// Room: shanlu1.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
上得峰来，但见山势险峻，树木清幽，鸟鸣嘤嘤，流水淙
淙。你越山脊而上，两崖深不见底，凡险峻处，如身置太空，
肝摇胆撼。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhandao",
  "northwest" : __DIR__"banshanting",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

