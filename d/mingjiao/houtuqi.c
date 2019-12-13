// Room: houtuqi.c

inherit ROOM;

void create()
{
        set("short", "厚土旗");
        set("long", @LONG
这里是明教厚土旗。旗中教众个个膀粗腰圆，力大无穷的样子。
数十年来的辛苦劳作,把光明顶建设得坚固无比。与分列四角的锐金
、巨木、洪水、烈火四旗互相呼应，共担防守重任。
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanyuan" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guangming-ding",
  "north" : __DIR__"guangchang1",
  "west" : __DIR__"lianwu-chang3",
  "east" : __DIR__"lianwu-chang1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

