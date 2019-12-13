inherit ROOM;

void create()
{
	set("short", "竹海");
	set("long", @LONG
竹海枝叶浓密，地上积雪并没有多少，沙沙的竹叶随着冷风作响，偶有雪花坠落。
渐渐深入一点之后，也能感觉到有一丝迷雾在竹林之中弥漫。路边竖着一块石碑，
刻着：
     【须弥紫竹阵，破阵者方可入内！】

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

