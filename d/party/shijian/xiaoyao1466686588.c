inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ʿ��˾�ĵ���������������ٹ̵��Ǹ��÷��Ӹ�����ۻ�÷��ᶫ�ɷݺ;����۶��������

LONG
);
	set("exits", ([
"south" : "/d/party/shijian/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "shijian");
	
	setup();
}

