inherit ROOM;

void create()
{
	set("short", "�ɻ���");
	set("long", @LONG
һ���޼ʵĺɻ�����һ����ȥ��������Ҷ����Ҷ��«έ�����ף�
����һģһ������֮��Ҷ����Ҷ��ˮ��Ư������ʱһ�������
�㼴�仯�ٰ㣬����˿̼ǵ����������˲ʱ������ȫȻ��ͬ��

LONG
);
	set("exits", ([
"south" : "/d/party/yuerong/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

