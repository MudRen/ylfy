inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", @LONG
���Ƿ��Ʊ��������ң��ܶ�������ڴ��������Ӻ����꣬��Ѫ���ڣ���������ǰ��

LONG
);
	set("exits", ([
"south" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

