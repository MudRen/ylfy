inherit ROOM;

void create()
{
	set("short", "码头");
	set("long", @LONG
这是一个天然的海港，大大小小的商船在这里靠岸，秩序井然。海港在庄主的管理下，
蒸蒸日上，不少官船也从这里进出。

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

