inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������԰��ѵ�����أ��ܶ����˶��Ǵ����￪ʼ��ѵ����
����Ľ������ǳ��������ʹ�.

LONG
);
	set("exits", ([
"west" : "/d/party/vip/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "vip");
	
	setup();
}

