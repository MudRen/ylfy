//bye enter

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����¼�����һ�������صİ�����Ҳ��֪����˭�޽��ġ� 
LONG
	);

	set("exits", ([
			"north" : __DIR__"andao2",
                        "up" : __DIR__"xiaoting",
	]));

	setup();
	replace_program(ROOM);
}



