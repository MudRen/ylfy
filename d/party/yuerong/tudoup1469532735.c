inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径，路两旁绿柳成荫，一处处山石花木
点缀在其中。你走在实地上，啪嗒啪嗒的发出清脆的响声。

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/tudoub1466847400.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

