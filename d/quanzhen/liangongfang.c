// liangongfang.c ������
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ���λȫ���������ϥ������
�������
LONG
	);
	set("exits", ([
		"east" : __DIR__"xilang3",
	]));
	
	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
