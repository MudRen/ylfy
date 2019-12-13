inherit ROOM;

void create()
{
	set("short", "恶魔陪练室");
	set("long", @LONG
这是一间恶魔的陪练室里面摆满了各种各样的古董看着相当值钱这里真是金碧辉煌无与伦比实在是太厉害了大家都非常向往来这里因为只有在这里才能得到飞升
。
。

LONG
);
	set("exits", ([
"west" : "/d/party/emcity/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "emcity");
	
	setup();
}

