inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
ҩ�̲���ȴ�쳣�����ࣻ�����ǹ�̨����̨�����Ǹ���
���Ӽ��ٸ�С������һһ�ú�ֽ����ҩ�ĵ����ƣ������ݶ���
ǽ������һ��ڵ׽��ֵ��Ҷд�š����ֻش�����

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

