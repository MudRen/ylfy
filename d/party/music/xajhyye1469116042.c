inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǰ������´���������һ��Ƥ��ߴ��ι������������֮��Ҳ�ǰ�������Ȩ�����������߸�����һ������������

LONG
);
	set("exits", ([
"north" : "/d/party/music/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "music");
	
	setup();
}

