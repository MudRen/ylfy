inherit ROOM;

void create()
{
	set("short", "迷雾森林");
	set("long", @LONG
  传说中迷雾森林是通往精灵神界的必经之路。
  传说中迷雾森林是通往精灵神界的必经之路。
  传说中迷雾森林是通往精灵神界的必经之路。

LONG
);
	set("exits", ([
"west" : "/d/party/lm/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "lm");
	
	setup();
}

