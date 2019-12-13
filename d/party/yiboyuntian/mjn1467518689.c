inherit ROOM;

void create()
{
	set("short", "如花怡红院");
	set("long", @LONG
如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院如花开的怡红院

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

