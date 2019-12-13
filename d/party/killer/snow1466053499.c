inherit ROOM;

void create()
{
	set("short", "花满楼");
	set("long", @LONG
当年初卷芳髫。奈惯起逾丰渐逾高。见浴罢铜，罗巾掩早，围来绣袜，锦带拴牢。逗向瓜期，褪将裙底，天让何人吮似醪。幽欢再，为娇儿抛下，湿透重绡。

LONG
);
	set("exits", ([
"west" : "/d/party/killer/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

