inherit ROOM;

void create()
{
	set("short", "����ʥˮɽׯ");
	set("long", @LONG
���ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ��ٸ���

LONG
);
	set("exits", ([
"south" : "/d/party/yiboyuntian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yiboyuntian");
	
	setup();
}

