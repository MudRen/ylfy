inherit ROOM;

void create()
{
	set("short", "荷花荡");
	set("long", @LONG
一望无际的荷花荡。一眼望去，满湖荷叶，菱叶，芦苇，茭白，
都是一模一样，兼之荷叶，菱叶在水面漂浮，随时一阵风来，
便即变化百般，就算此刻记得清清楚楚，瞬时间局面便全然不同。

LONG
);
	set("exits", ([
"south" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

