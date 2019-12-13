// Room: shanjiao.c

inherit ROOM;

void create()
{
        set("short", "山脚下");
        set("long", @LONG
山风怒号，云蒸雾涌，一座大山悄然展现在你的眼前，它
一岭孤悬，长至三里，两旁陡绝，深陷万丈，远远看过去，就
好象一把雪亮的刀，斜斜的插在白云中。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luzhou",
  "north" : __DIR__"shanlu2",
  "northwest" : __DIR__"diecong2",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

