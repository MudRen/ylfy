// Room: /d/emei/shierpan4.c ������ ʮ����4

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ʮ����");
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶�����������
���֡�
LONG
	);

	set("exits", ([
                "westdown": __DIR__"shierpan3",
                "eastup" : __DIR__"huayanding",
	]));

	set("outdoors", "emei");
	setup();
}
