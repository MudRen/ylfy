inherit ROOM;

void create()
{
	set("short", "淫窝");
	set("long", @LONG
这是一间谷物加工厂这里是谷子脱壳成米的地方米厂老板是一个一看就知道是十分精明的干瘦的中年人老是带着一脸奸笑你可以看到许多人正在忙忙碌碌的工作着门口挂著一块牌子

LONG
);
	set("exits", ([
"west" : "/d/party/yinwo/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yinwo");
	
	setup();
}

