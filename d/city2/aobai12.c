
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������רΪ���ݴ�����ֱ�ӵ������õġ�
LONG
	);
	set("exits", ([
		"southwest" :  __DIR__"aobai11",
		"northeast" : __DIR__"bingqiku",
	]));
	setup();
	replace_program(ROOM);
}
