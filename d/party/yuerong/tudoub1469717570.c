inherit ROOM;

void create()
{
	set("short", "庄园");
	set("long", @LONG
突然一阵清香涌至，眼前无边无际的全是薰衣草，原来地上是浅浅的
一片水塘，深不逾尺，种满了薰衣草。漫山遍野的花丛，很难辨清
道路。一种迥异的香味在空气中弥漫着。

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/nandajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

