inherit ROOM;

void create()
{
	set("short", "ׯ԰");
	set("long", @LONG
ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��޹�²ݣ�ԭ��������ǳǳ��
һƬˮ�������ߣ�������޹�²ݡ���ɽ��Ұ�Ļ��ԣ����ѱ���
��·��һ���������ζ�ڿ����������š�

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/nandajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

