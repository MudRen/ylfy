inherit ROOM;

void create()
{
	set("short", "�绨����Ժ");
	set("long", @LONG
�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ�绨��������Ժ

LONG
);
	set("exits", ([
"north" : "/d/party/yiboyuntian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yiboyuntian");
	
	setup();
}

