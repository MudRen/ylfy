inherit ROOM;

void create()
{
	set("short", "华山论剑");
	set("long", @LONG
东邪、西毒、南帝、北丐、中神通，在华山比武。最后却都输给了老张，老张淡泊名利，改名为：陪练教头。

LONG
);
	set("exits", ([
"northeast" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

