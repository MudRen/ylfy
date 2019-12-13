inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
忙碌了一天，坐下来喝口大碗茶，听说书先生说些江湖上的奇闻轶事，
偶尔会有一些陌生的江湖人在这里出现，但是，只要正经地守规矩，
打开门做生意，来的都是客人。

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

