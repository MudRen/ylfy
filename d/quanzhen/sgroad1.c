// sgroad1.c ɽ��С·

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ���ϸԵ�С·�ϣ����߶���ï�ܵ����֣��Զ���������ϡ�ɼ���
LONG
	);
	set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"sgroad2",
		"eastdown" : __DIR__"fanchuan",
	]));

	setup();
}

