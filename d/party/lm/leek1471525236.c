inherit ROOM;

void create()
{
	set("short", "����ɭ��");
	set("long", @LONG
  ��˵������ɭ����ͨ���������ıؾ�֮·��
  ��˵������ɭ����ͨ���������ıؾ�֮·��
  ��˵������ɭ����ͨ���������ıؾ�֮·��

LONG
);
	set("exits", ([
"west" : "/d/party/lm/beidajie5.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "lm");
	
	setup();
}

