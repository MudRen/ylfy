inherit ROOM;

void create()
{
	set("short", "Ò¹Ò¹¾­ÑéÊÒ");
	set("long", @LONG
¿ª½£»ê¿¦¿¦¿¦¿ª½£»ê¿¦¿¦¿¦¿ª½£»ê¿¦¿¦¿¦¿ª½£»ê¿¦¿¦¿¦¿ª½£»ê¿¦¿¦¿¦

LONG
);
	set("exits", ([
"north" : "/d/party/jh/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "jh");
	
	setup();
}

