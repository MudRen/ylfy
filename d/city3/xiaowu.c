// Room: /d/city3/xiaowu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
一间四周空荡荡，什麽摆设也没有的空房间。只在房子中间放着
一张桌子，桌子上摆满了雕镌的工具。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhubaodian",
]));

        set("objects", ([ 
  __DIR__"npc/xie" : 1,
]));

	setup();
	replace_program(ROOM);
}
