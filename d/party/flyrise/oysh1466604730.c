inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
˵�������������߳��Ͽ���ͨ�����ָ���ڰ������Ͻ���ˢ�����õ������ҡ�

LONG
);
	set("exits", ([
"east" : "/d/party/flyrise/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "flyrise");
	
	setup();
}

