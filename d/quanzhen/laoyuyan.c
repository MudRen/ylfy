// laoyuyan.c 老妪岩 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "老妪岩");
	set("long", @LONG
只见迎面一块大岩石当道，形状阴森可怖，自空凭临，宛似一个
老妪弯腰俯视。往上是宝泉。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"eastdown" : __DIR__"baoziyan",
		"northup" : __DIR__"baoquan",
        ]));
	setup();
	replace_program(ROOM);
}



