// Room: /d/cxwxm/feifeng2.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "飞凤憩");
        set("long", @LONG
这里是门主的闺房，也是她日常梳妆打扮的地方，放着一张香木梳妆台，
上面镶嵌着的是一面古香古色的铜镜。梳妆台上还残留着花粉的余痕。在台旁
摆放着一人高的大花瓶中插满了散发着清香的茉莉花。

LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"feifeng",
  "west" : __DIR__"feifeng3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
