// donglang3.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������м������ң��������������֡�
LONG
	);

	set("exits", ([
	     "east" : __DIR__"xiuxishi",
           "west" : __DIR__"houdian",
       ]));

		
	setup();
       replace_program(ROOM);

}
