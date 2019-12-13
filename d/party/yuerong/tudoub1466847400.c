inherit ROOM;

void create()
{
	set("short", "花房");
	set("long", @LONG
这里是庄主少年时练功的地方，虽然已经不需要了，但还是一尘不染，阳光透过窗台洒在了地面上，让人感觉暖洋洋的。

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/tudoup1469532735",
"west" : "/d/party/yuerong/beidajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

