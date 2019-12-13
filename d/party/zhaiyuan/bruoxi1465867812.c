inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
帮会帮主或者长老可以通过这个指令在帮会地盘上建设刷经验用的陪练室。

LONG
);
	set("exits", ([
"down" : "/d/party/zhaiyuan/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "zhaiyuan");
	
	setup();
}

