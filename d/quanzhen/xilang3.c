//xilang3.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ�������ϣ������Ǻ���������������
LONG
	);

	set("exits", ([
	     "west" : __DIR__"liangongfang",
           "east" : __DIR__"houdian",
          ]));
	setup();
	replace_program(ROOM);
}
