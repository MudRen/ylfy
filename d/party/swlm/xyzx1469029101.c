inherit ROOM;

void create()
{
	set("short", "��ɽ�۽�");
	set("long", @LONG
��а���������ϵۡ���ؤ������ͨ���ڻ�ɽ���䡣���ȴ����������ţ����ŵ�������������Ϊ��������ͷ��

LONG
);
	set("exits", ([
"northeast" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

