// Room: /d/songshan/cangku.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "�ֿ�");
	set("long", @LONG
����һ���ֿ⣬�����ܲ�͸�硣��һ���ű��ŵ�һ��ùζ�����ݵ�
�ҳ����ɶѳɶѵ���Ʒ����������䷿�䡣
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
	create_door("north" , "ľ��", "south" , DOOR_CLOSED);
}

