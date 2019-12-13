inherit ROOM;

void create()
{
	set("short", "åª¹¸Èª");
	set("long", @LONG
Ò»ÆøÎŞ¶¬ÏÄ£¬ÈıÇïÓÀ×¢´º¡£Ñ×²¨Èç¶¦·Ğ£¬ÈÈÀËËÆÌÀĞÂ¡£·ÖÁï×ÌºÌ¼Ú£¬Í£Á÷µ´Ë×³¾¡£ä¸ä¸ÖéÀá·º£¬¹ö¹öÓñÍÅ½ò¡£

LONG
);
	set("exits", ([
"east" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

