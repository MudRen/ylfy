// sgroad2.c ɽ��С·

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
		"southdown" : __DIR__"sgroad1",
		"northup" : __DIR__"gangding",
	]));

  
	setup();
}

