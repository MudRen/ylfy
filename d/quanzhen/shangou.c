// shangou.c ɽ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����ǰ��һ���ֳ������ɽ����
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"" : __DIR__"",
		"" : __DIR__"",
             "": __DIR__"" 
	]));
	setup();
	replace_program(ROOM);
}



