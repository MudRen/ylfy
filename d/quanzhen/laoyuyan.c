// laoyuyan.c ������ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ֻ��ӭ��һ�����ʯ��������״��ɭ�ɲ����Կ�ƾ�٣�����һ��
�����������ӡ������Ǳ�Ȫ��
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



