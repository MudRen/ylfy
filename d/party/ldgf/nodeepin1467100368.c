inherit ROOM;

void create()
{
	set("short", "������ԥ");
	set("long", @LONG
����ռ��Ϸ�������Сʫ�����굯ָ�������˷ǣ�����ϡ��������֮�ࡱ���������ڿ��У��������֡�

LONG
);
	set("exits", ([
"north" : "/d/party/ldgf/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "ldgf");
	
	setup();
}

