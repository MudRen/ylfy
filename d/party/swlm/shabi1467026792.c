inherit ROOM;

void create()
{
	set("short", "華清池");
	set("long", @LONG
山姿水态冠秦疆，美色当初醉李唐。只把风怀传妙丽，依然韵致舞霓裳。恨歌独宠痴情圣，遗憾千年错位皇。一去红尘人已换，满园腰似楚宫娘。

LONG
);
	set("exits", ([
"south" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

