inherit ROOM;

void create()
{
	set("short", "学堂");
	set("long", @LONG
庄里的小孩儿都在这里念书，先生是个四十岁左右的外乡人，据说
考过秀才，主要教三字经等启蒙的书，没有人知道他的来历，他也
从来没有和任何人提起过

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

