inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ƿ��Ʊ��ĵڶ�����ϰ�ң�Ҳ�кܶ����ڴ���Ѫ������Ϊ���е�������ܶ���Ϊ�����������Ŭ��
��

LONG
);
	set("exits", ([
"east" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

