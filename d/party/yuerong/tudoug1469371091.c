inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
æµ��һ�죬�������ȿڴ���裬��˵������˵Щ�����ϵ��������£�
ż������һЩİ���Ľ�������������֣����ǣ�ֻҪ�������ع�أ�
���������⣬���Ķ��ǿ��ˡ�

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

