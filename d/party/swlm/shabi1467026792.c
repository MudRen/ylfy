inherit ROOM;

void create()
{
	set("short", "�A���");
	set("long", @LONG
ɽ��ˮ̬���ؽ�����ɫ���������ơ�ֻ�ѷ绳����������Ȼ���������ѡ��޸�������ʥ���ź�ǧ���λ�ʡ�һȥ�쳾���ѻ�����԰���Ƴ����

LONG
);
	set("exits", ([
"south" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

