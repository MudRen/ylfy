inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
������ˣ�����Ǧ���䣬��Ц��Ȼ�����ģ�������ǰ���⡣�������걭ʱ�������ܳ��´ʣ���������������ϳ�һ����֫��

LONG
);
	set("exits", ([
"east" : "/d/party/killer/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "killer");
	
	setup();
}

