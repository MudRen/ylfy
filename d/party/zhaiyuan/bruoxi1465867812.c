inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������߳��Ͽ���ͨ�����ָ���ڰ������Ͻ���ˢ�����õ������ҡ�

LONG
);
	set("exits", ([
"down" : "/d/party/zhaiyuan/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "zhaiyuan");
	
	setup();
}

