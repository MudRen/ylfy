// shijie2.c ʯ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ�����ͱڣ�
һ�������£�̧ͷ��Լ�ɼ������������е�ɽ�壬������ˮ���ȣ�������
��������������̫�Һ���
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"eastdown" : __DIR__"shijie1",
		"northup" : __DIR__"taiyihu",
	]));
	setup();
	replace_program(ROOM);
}
