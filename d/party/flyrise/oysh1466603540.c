inherit ROOM;

void create()
{
	set("short", "妓院");
	set("long", @LONG
旁边便是花梨木几椅，用来招呼群雄或帮众汇报大小事务的休息地方。

LONG
);
	set("exits", ([
"south" : "/d/party/flyrise/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "flyrise");
	
	setup();
}

