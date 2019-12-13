inherit ROOM;

void create()
{
	set("short", "妓院");
	set("long", @LONG
说明：帮会帮主或者长老可以通过这个指令在帮会地盘上建设刷经验用的陪练室。

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

