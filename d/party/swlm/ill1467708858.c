inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ڹ�����Ԫʼ�����鱦���𡢵������𡣵���һ��һ������������������������︺����������������Ϊ�͡�

LONG
);
	set("exits", ([
"up" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

