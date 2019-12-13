inherit ROOM;

void create()
{
	set("short", "青楼");
	set("long", @LONG
拊手应留，当胸小染，两点魂销。讶素影微笼，雪堆姑射，紫尖轻晕，露滴葡萄。漫说酥凝，休夸菽发，玉润珠圆比更饶。开襟处，正粉香欲藉，花气难消。
。

LONG
);
	set("exits", ([
"south" : "/d/party/killer/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

