inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long", @LONG
殿内供奉着元始天尊、灵宝天尊、道德天尊。道生一，一生二，二生三，三生万物，万物负阴而抱阳，冲气以为和。

LONG
);
	set("exits", ([
"up" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

