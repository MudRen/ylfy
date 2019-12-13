// Room: niushi.c

inherit ROOM;

void create()
{
        set("short", "牛棚");
        set("long", @LONG
小小的牛棚，瘦瘦的老牛，嗡嗡的苍蝇，冷冷的寒风，脏脏
的水槽，堆堆的茅草，这一切一切，均展现在你的面前，让你呆
呆得发愣，难道这就是员外说的宝牛！真不能让人相信！
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhang-shi",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/niu" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

