inherit ROOM;

void create()
{
	set("short", "���ź�");
	set("long", @LONG
����������ź����̲����죬����������͸��������Լ�ɼ���������һ�Ҵ������Ǵ��ϲ�û���ˡ�

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie2.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

