inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����������ö���ʯ�̳ɵ�С����·������������һ����ɽʯ��ľ
��׺�����С�������ʵ���ϣ�ž�žવķ�������������

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/tudoub1466847400.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

