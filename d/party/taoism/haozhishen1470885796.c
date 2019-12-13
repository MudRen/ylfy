inherit ROOM;

void create()
{
	set("short", "啪啪啪");
	set("long", @LONG
你眼前出现雾蒙蒙的一片。这里是碎梦大坏蛋指定的经验来源，有环意识玩家都特别恨他，从来不就不喜欢他，总是称碎梦为坑梦。

LONG
);
	set("exits", ([
"south" : "/d/party/taoism/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "taoism");
	
	setup();
}

