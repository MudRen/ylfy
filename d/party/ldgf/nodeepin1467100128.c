inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������Զ��¹����ڤ��ƽ�����ǵ��ĵط������Ĵ��ţ�������һƬ�����ֱͨ��񷣬���Ϸ��ǵ�㣬Ԥʾ�Ų���Ԥ֪��δ����

LONG
);
	set("exits", ([
"east" : "/d/party/ldgf/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "ldgf");
	
	setup();
}

