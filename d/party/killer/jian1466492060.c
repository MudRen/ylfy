inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ����һ��˶��������ѡ����������ݳ������ķ���ѻ������л�����ʶ�ĺ�����ң�������������ӷ�����ǰ������ӵ���������

LONG
);
	set("exits", ([
"up" : "/d/party/killer/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

