inherit ROOM;

void create()
{
	set("short", "迷雾森林");
	set("long", @LONG
这里是帮内的练武场宽敞而干净汉白玉砌的地面面被雨水冲得光明如镜
四周摆放着各种武器角落里有几个帮众在讨论武艺广场四周种满了珍奇的花草。

LONG
);
	set("exits", ([
"west" : "/d/party/luoxia/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "luoxia");
	
	setup();
}

