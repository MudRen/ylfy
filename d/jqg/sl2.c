
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ�����͵�ɽ·�����ɽ���Ѷ�ȥ��
LONG
	);

	set("exits", ([
                "westup" : __DIR__"sl3",
                "southdown" : __DIR__"sl1",
	]));
 

        set("outdoors", "����");
	setup();
	replace_program(ROOM); 
}

