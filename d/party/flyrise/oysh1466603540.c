inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�Ա߱��ǻ���ľ���Σ������к�Ⱥ�ۻ���ڻ㱨��С�������Ϣ�ط���

LONG
);
	set("exits", ([
"south" : "/d/party/flyrise/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "flyrise");
	
	setup();
}

