// Room: /d/emei/shierpan1.c ������ ʮ����1


inherit ROOM;




void create()
{
	set("short", "ʮ����");
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶������������֣�
���򵽰�������
LONG
	);

	set("exits", ([
                "west" : __DIR__"wannianan",
                "eastup": __DIR__"shierpan2",
                "northdown":  __DIR__"bailongdong",
	]));

	set("outdoors", "emei");
	setup();
}



