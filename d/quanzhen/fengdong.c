// fengdong.c 风洞 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "风洞");
	set("long", @LONG
这里是风洞。洞高一十五米，深四十米，是有二大花岗夹峙而成。洞内清风习习，凉气
飕飕，是一个避暑的好地方。往北是冰洞。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"east" : __DIR__"taiyihu",
		"north" : __DIR__"bingdong",
	]));
	setup();
	replace_program(ROOM);
}

