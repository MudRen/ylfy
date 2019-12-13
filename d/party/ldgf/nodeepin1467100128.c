inherit ROOM;

void create()
{
	set("short", "海空天空");
	set("long", @LONG
这里是远古鹿鼎公冥想平常心是道的地方，宽敞的大门，里面有一片汪洋大海直通苍穹，天上繁星点点，预示着不可预知的未来。

LONG
);
	set("exits", ([
"east" : "/d/party/ldgf/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "ldgf");
	
	setup();
}

