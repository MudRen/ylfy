inherit ROOM;

void create()
{
	set("short", "果园");
	set("long", @LONG
转过山腰，出现一大片果林。一颗颗果树长得高大茂盛，枝叶繁密，
累累鲜果，鲜嫩诱人，清风拂叶，沙沙作响，更令这群果树随风招摇
起舞，送来阵阵果香。

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/nandajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

