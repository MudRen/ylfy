// shanjiao.c ����ɽ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���
һ��ʯ����ɽ�����죬���ż�������͡�ʯ���Ͽ��š�����ɽ��
�������֣�ԭ�����������������ȫ������ڵ�����ɽ�ˡ�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"east" : __DIR__"gangding",
		"northup" : __DIR__"shijie1",
	]));
	setup();
	replace_program(ROOM);
}
