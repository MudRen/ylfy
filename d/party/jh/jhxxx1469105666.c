inherit ROOM;

void create()
{
	set("short", "ҹҹ�������");
	set("long", @LONG
������ʥ���ڰ����յ½�㰡�͸���Ұ�ʲ�ٸ¸¼ƻ����ù���˾�����ؼҰ�˯�����͸���Ұ���˾�Ļ���

LONG
);
	set("exits", ([
"south" : "/d/party/jh/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "jh");
	
	setup();
}

