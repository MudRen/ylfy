// yuqingchi.c �����

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������أ�����Ⱥɽ����������β��羵����ˮ������������
���͵��䡢�������֣�һ������浾����崿�����ķ�⡣���Ͼ���ȫ��
�̡�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"shijie3",
		"eastup" : __DIR__"sheshentai",
       ]));
	setup();
	replace_program(ROOM);
}



