inherit ROOM;

void create()
{
	set("short", "Ϧ����ʿר��������");
	set("long", @LONG
������Ϧ����ʿ�ĸ���ר�������ϣ�һ������²��ñ��˽���ġ�������һ��������ͷ�������������Ͷ���

LONG
);
	set("exits", ([
"down" : "/d/party/shijian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "shijian");
	
	setup();
}

