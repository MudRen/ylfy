// Room: /d/songshan/cangku.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "仓库");
	set("long", @LONG
这是一个仓库，四周密不透风。你一进门便闻到一股霉味，满屋的
灰尘，成堆成堆的物品快堆满了整间房间。
LONG );
	set("exits" , ([
		"north" : __DIR__"westting",
	]) );
	set("objects" , ([
		__DIR__"obj/beixin" : 1,
		__DIR__"obj/huwan" : 1,
		__DIR__"obj/huxin" : 1,
		__DIR__"obj/huyao" : 1,
		__DIR__"obj/huzhi" : 1,
		__DIR__"obj/niupi" : 1,
		__DIR__"obj/shadai" : 1,
		__DIR__"obj/tengjia" : 1,
		__DIR__"obj/tiejia" : 1,
	]) );
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
	create_door("north" , "木门", "south" , DOOR_CLOSED);
}

