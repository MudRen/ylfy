inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
一个用来练功的广场
周围放满了十八般兵器
四周还有很多梅花桩和木人
城管队员在这里练习武艺

LONG
);
	set("exits", ([
"north" : "/d/party/cg/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "cg");
	
	setup();
}

