inherit ROOM;

void create()
{
	set("short", "���ũ���ɹ�");
	set("long", @LONG
���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ���ũ

LONG
);
	set("exits", ([
"east" : "/d/party/yiboyuntian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yiboyuntian");
	
	setup();
}

