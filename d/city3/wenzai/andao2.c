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
			"north" : __DIR__"andao3",
                        "south" : __DIR__"andao1",
	]));

	setup();
	replace_program(ROOM);
}



