inherit ROOM;

void create()
{
	set("short", "陪练三室");
	set("long", @LONG
春花秋月何时了，往事知多少；小楼昨夜又东风，故国不堪回首月明中；雕栏玉砌应犹在，只是朱颜改；问君能有几多愁，恰似一江春水向东流

LONG
);
	set("exits", ([
"north" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

