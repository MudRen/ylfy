inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ׯ������ʱ�����ĵط�����Ȼ�Ѿ�����Ҫ�ˣ�������һ����Ⱦ������͸����̨�����˵����ϣ����˸о�ů����ġ�

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/tudoup1469532735",
"west" : "/d/party/yuerong/beidajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

