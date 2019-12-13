inherit ROOM;

void create()
{
	set("short", "夕阳武士专用陪练室");
	set("long", @LONG
这里是夕阳武士的个人专用陪练窒，一般情况下不让别人进入的。这里有一个陪练教头，练功就找他就对了

LONG
);
	set("exits", ([
"down" : "/d/party/shijian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "shijian");
	
	setup();
}

