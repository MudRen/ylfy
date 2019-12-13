inherit ROOM;

void create()
{
	set("short", "陪练室");
	set("long", @LONG
一个用来练功的屋子
一个用来练功的屋子
一个用来练功的屋子
一个用来练功的屋子

LONG
);
	set("exits", ([
"down" : "/d/party/cg/porh1466088935.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "cg");
	
	setup();
}

