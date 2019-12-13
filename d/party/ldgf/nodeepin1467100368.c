inherit ROOM;

void create()
{
	set("short", "不再犹豫");
	set("long", @LONG
虚拟空间上方有四行小诗“百年弹指，物是人非，游离稀世，淡泊之侧”，隐隐藏于空中，若隐若现。

LONG
);
	set("exits", ([
"north" : "/d/party/ldgf/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "ldgf");
	
	setup();
}

