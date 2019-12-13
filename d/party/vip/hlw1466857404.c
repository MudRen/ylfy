inherit ROOM;

void create()
{
	set("short", "陪练室");
	set("long", @LONG
这里是新手乐园的训练基地，很多新人都是从这里开始的训练，
这里的教练都是出了名的耐打.

LONG
);
	set("exits", ([
"west" : "/d/party/vip/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "vip");
	
	setup();
}

