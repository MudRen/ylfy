inherit ROOM;

void create()
{
	set("short", "麦金农神剑仙宫");
	set("long", @LONG
麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农麦金农

LONG
);
	set("exits", ([
"east" : "/d/party/yiboyuntian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yiboyuntian");
	
	setup();
}

