inherit ROOM;

void create()
{
	set("short", "摘星楼");
	set("long", @LONG
在充满想象的暗黑背景里，一个身着红色露背长裙的曼妙背影闪着诱人之光，这背影既像舒淇，又像林志玲。女郎一只玉臂藏于身后，纤纤玉手握着一条小皮鞭，恰到好处地搭在臀部上缘。

LONG
);
	set("exits", ([
"down" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

