// shijie4.c ʯ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ����
�ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е�ɽ�壬������ˮ��
�ȣ������Ŀ�������������ȫ���ɽ�š�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"southdown" : __DIR__"shijie3",
		"northup" : __DIR__"shanmen",
	]));
	setup();
	replace_program(ROOM);
}
