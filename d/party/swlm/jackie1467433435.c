inherit ROOM;

void create()
{
	set("short", "盤絲洞");
	set("long", @LONG
褪放纽扣儿，解开罗带结。酥胸白似银，玉体浑如雪。肘膊赛凝胭，香肩欺粉贴。肚皮软又绵，脊背光还洁。膝腕半围团，金莲三寸窄。中间一段情，露出风流穴。

LONG
);
	set("exits", ([
"north" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

