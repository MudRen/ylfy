// bingdong.c ���� 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǳ��������ڶ��Ǽ�Ӳ�ı��顣����ʢ�ģ�����߽�������
��ɼ��������������,��ʱ�б������Ŀ��ܡ�����书��ǿ֮�ˣ���
���޷��ڶ��о�����
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"fengdong",
			]));
	setup();
	replace_program(ROOM);
}


