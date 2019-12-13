inherit ROOM;

void create()
{
	set("short", "陪练室");
	set("long", @LONG
一个陪练室
一个陪练室
一个陪练室
一个陪练室
一个陪练室
一个陪练室
一个陪练室
一个陪练室

LONG
);
	set("exits", ([
"down" : "/d/party/cg/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "cg");
	
	setup();
}

