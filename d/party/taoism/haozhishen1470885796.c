inherit ROOM;

void create()
{
	set("short", "žžž");
	set("long", @LONG
����ǰ���������ɵ�һƬ�����������δ󻵵�ָ���ľ�����Դ���л���ʶ��Ҷ��ر�������������Ͳ�ϲ���������ǳ�����Ϊ���Ρ�

LONG
);
	set("exits", ([
"south" : "/d/party/taoism/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "taoism");
	
	setup();
}

