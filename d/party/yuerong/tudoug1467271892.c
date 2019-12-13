inherit ROOM;

void create()
{
	set("short", "剑冢");
	set("long", @LONG
大石上「剑冢」两个大字之旁，尚有两行字体较小的石刻：
「剑魔独孤求败既无敌於天下，乃埋剑於斯。
呜呼！群雄束手，长剑空利，不亦悲夫！」

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie2.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

