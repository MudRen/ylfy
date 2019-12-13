inherit ROOM;

void create()
{
	set("short", "白楼");
	set("long", @LONG
芳年妙妓，淡拂铅华翠，轻笑自然生百媚，争那尊前人意。酒倾琥珀杯时，更堪能唱新词，赠得王孙独处，断肠一搦腰肢。

LONG
);
	set("exits", ([
"east" : "/d/party/killer/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

