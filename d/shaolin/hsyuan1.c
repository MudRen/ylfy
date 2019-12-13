// Room: /d/shaolin/hsyuan1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "和尚院一部");
    set("long", @LONG
这里是和尚院待客的地方，靠墙左右两侧摆着一溜太师椅。
墙角一几，放着几个茶壶。有个茶壶壶身上题了“碧螺春”三
个篆字，壶嘴热气腾腾，似乎是刚沏的新茶。一位小沙弥在一
边垂手站立。
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao-tong" : 1,
  "/kungfu/class/shaolin/hui-he" : 1,
]));
    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhulin1",
  "south" : __DIR__"zoulang7",
  "north" : __DIR__"hsyuan2",
  "west" : __DIR__"wuchang3",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
