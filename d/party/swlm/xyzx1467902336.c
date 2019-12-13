inherit ROOM;

void create()
{
	set("short", "女娲行宫");
	set("long", @LONG
殿前华丽，五彩金；金童对对执幢，玉女双双捧如意。玉钩斜挂，半轮新月悬空；宝帐婆娑，万对彩鸾朝斗。碧落床边，俱是舞鹤翔鸾；沉香宝座，造就走龙飞凤。飘飘奇彩异寻常，金炉瑞霭；袅袅祯祥腾紫雾，银烛辉煌。

LONG
);
	set("exits", ([
"west" : "/d/party/swlm/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

