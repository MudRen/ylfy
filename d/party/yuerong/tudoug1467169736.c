inherit ROOM;

void create()
{
	set("short", "悦榕湖");
	set("long", @LONG
这里就是悦榕湖，烟波浩渺，淫雨霏霏，透过大雾，隐约可见江面上有一艘船，但是船上并没有人。

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie2.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

