inherit ROOM;

void create()
{
	set("short", "经验专用");
	set("long", @LONG
经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用经验专用

LONG
);
	set("exits", ([
"east" : "/d/party/wudi/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "wudi");
	
	setup();
}

