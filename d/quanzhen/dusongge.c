// dusongge.c ���ɸ� 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ɸ�");
	set("long", @LONG
�����Ƕ��ɸ��뱦Ȫͬλ��ɽ����Ӧ������һ��ǧ����ɶ���
�������������ﻨ�㣬��ɫ�续��Ϊ��ʤ֮�ѵء������ǹ���̨��
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"west" : __DIR__"baoquan",
		"northup" : __DIR__"guanyintai",
        ]));
	setup();
	replace_program(ROOM);
}



