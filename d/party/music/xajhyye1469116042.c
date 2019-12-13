inherit ROOM;

void create()
{
	set("short", "尊贵包厢");
	set("long", @LONG
这里是帮派议事大厅上首有一虎皮金边大椅供帮主休憩议事之用也是帮内至上权威的象征两边各竖着一块黑漆金字牌匾

LONG
);
	set("exits", ([
"north" : "/d/party/music/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "music");
	
	setup();
}

