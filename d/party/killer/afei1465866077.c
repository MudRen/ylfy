inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����Ӧ��������СȾ���������������Ӱ΢����ѩ�ѹ��䣬�ϼ����Σ�¶�����ѡ���˵�������ݿ��ķ���������Բ�ȸ��ġ����󴦣����������壬����������
��

LONG
);
	set("exits", ([
"south" : "/d/party/killer/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

