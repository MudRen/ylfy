inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
ת��ɽ��������һ��Ƭ���֡�һ�ſŹ������øߴ�ïʢ��֦Ҷ���ܣ�
�����ʹ����������ˣ�����Ҷ��ɳɳ���죬������Ⱥ���������ҡ
���裬����������㡣

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/nandajie1.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

