inherit ROOM;

void create()
{
	set("short", "笑傲江湖");
	set("long", @LONG
“易筋经”本是佛门神功，为何竟会令到修习之人性欲高涨？原来人体经络本是天生，上天造物自有其理，强行以后天之力易筋练功，虽能习得绝世神功，却是大干天和之事。

LONG
);
	set("exits", ([
"southeast" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

