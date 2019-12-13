inherit ROOM;

void create()
{
	set("short", "陪练二室");
	set("long", @LONG
这是飞云堡的第二个练习室，也有很多人在此流血流汗，为心中的梦想而奋斗，为江湖的梦想而努力
。

LONG
);
	set("exits", ([
"east" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

