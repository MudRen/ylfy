// Room: /d/wudie/qjm.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "琼景园");
        set("long", @LONG
来到园中，不由自主被园中的景物吸引。园中遍布不知名的奇花异
草。前面是一帘巨大的瀑布。溅起层层水雾，在阳光照耀下，架起一座
彩虹。瀑布下面是一个碧绿的水潭，倒影着奇花异草。水潭当中有一座
假山。假山上肯定很好玩，还是跳(jump)上去耍一下。
LONG
);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jm",
  "north" : __DIR__"pxt",
]));

        setup();
        replace_program(ROOM);
}
