//xilang5.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������������ϡ�
LONG
	);

	set("exits", ([
	     "southwest" : __DIR__"yuanchendian",
             "east" : __DIR__"donglang5",
	]));
	setup();
	replace_program(ROOM);
}
