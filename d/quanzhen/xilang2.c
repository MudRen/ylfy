//xilang2.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������������ϡ�����һ��֧�ڱ�����ϼ����ϣ���һ����
���ϱ߰��ɵ���ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ������ӵġ����¾�����
�����ǰ��ɵ�������ϼ��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"baxiandian",
             "north" : __DIR__"nanjidian",
	]));
	setup();
	replace_program(ROOM);
}
