inherit ROOM;

void create()
{
	set("short", "陪练一室");
	set("long", @LONG
这是飞云堡的练功室，很多弟子正在此练功，挥汗如雨，热血沸腾，向这梦想前进

LONG
);
	set("exits", ([
"south" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

