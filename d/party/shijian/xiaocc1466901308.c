inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʽ�����ѵ�������Ŷ��ٸ������Ļظ����úܸ����������о�����ͻȻһ����Ա��ٸԸ��Ϸʽ��

LONG
);
	set("exits", ([
"up" : "/d/party/shijian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "shijian");
	
	setup();
}

