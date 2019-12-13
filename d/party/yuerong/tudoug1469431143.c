inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
药铺不大，却异常的整洁；正面是柜台，柜台后面是个大
柜子几百个小抽屉上一一用红纸标着药材的名称；靠近屋顶的
墙上悬着一块黑底金字的匾额，写着“妙手回春”。

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

