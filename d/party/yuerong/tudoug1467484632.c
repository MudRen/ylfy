inherit ROOM;

void create()
{
	set("short", "演武场");
	set("long", @LONG
威严肃穆的校场之上已经挤满了黑压压的人群，汉白玉铺成的巨大会场之上架着巨大比武擂台，
擂台的旁边排满着各门各派的江湖弟子，每个人都带着兴奋的神色跃跃欲试的样子。

LONG
);
	set("exits", ([
"south" : "/d/party/yuerong/tudoub1466848465.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

