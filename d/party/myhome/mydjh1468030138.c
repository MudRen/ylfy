inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�������º�ʱ�ˣ�����֪���٣�С¥��ҹ�ֶ��磬�ʹ��������������У���������Ӧ���ڣ�ֻ�����ոģ��ʾ����м���ǡ��һ����ˮ����

LONG
);
	set("exits", ([
"north" : "/d/party/myhome/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "myhome");
	
	setup();
}

