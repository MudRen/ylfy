inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
你眼前出现了一片很大的广场眼前变得变得豁然开阔原来这是帮内东边的一个练武场四周都是高山直入云间，形成一个天然的盆地，这里常年大雨连绵也是帮众练武的极佳场地，听说在这里练功可以事半功倍。
。

LONG
);
	set("exits", ([
"west" : "/d/party/luoxia/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "luoxia");
	
	setup();
}

