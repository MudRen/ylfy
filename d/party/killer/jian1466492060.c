inherit ROOM;

void create()
{
	set("short", "瓦砾场");
	set("long", @LONG
你眼前出现一座硕大的垃圾堆。这里是扬州城内最大的废物堆积处，有环保意识的好心玩家，从来不随地乱扔废物，总是把他们扔到这里来。

LONG
);
	set("exits", ([
"up" : "/d/party/killer/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

