// Room: /d/emei/shierpan2.c ������ ʮ����2

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶���������
���֡�
LONG
	);

	set("exits", ([
                "westdown":  __DIR__"shierpan1",
                "eastup": __DIR__"shierpan3",
	]));

	set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}



