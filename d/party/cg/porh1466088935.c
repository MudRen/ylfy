inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ���ܴ��������
һ���ܴ��������
һ���ܴ��������
һ���ܴ��������
һ���ܴ��������
һ���ܴ��������
һ���ܴ��������
e
e
e
e
,
,
,
,
,
l
l
,
,

LONG
);
	set("exits", ([
"east" : "/d/party/cg/poro1466489104",
"west" : "/d/party/cg/poro1466489085",
"up" : "/d/party/cg/poro1466489058",
"south" : "/d/party/cg/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "cg");
	
	setup();
}

