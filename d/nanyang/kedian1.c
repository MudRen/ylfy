// Room: /d/nanyang/kedian1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "悦来客栈");
    set("long", @LONG
这是一家远近闻名的悦来客栈，生意非常兴隆。外地游客多选择
在这里落脚，你可以在这里打听到各地的风土人情。店小二里里外外
忙得团团转，接待着南腔北调的客人。墙上挂着一个牌子(paizi)。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/xiao-er" : 1,
]));
    set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "楼上雅房，每夜五两白银。
",
]));
    set("valid_startroom", 1);
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kedian2",
  "west" : __DIR__"nanyang",
]));
    setup();
    replace_program(ROOM);
}
