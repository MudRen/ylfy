inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
��֦ҶŨ�ܣ����ϻ�ѩ��û�ж��٣�ɳɳ����Ҷ����������죬ż��ѩ��׹�䡣
��������һ��֮��Ҳ�ܸо�����һ˿����������֮��������·������һ��ʯ����
���ţ�
     �����������������߷������ڣ���

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

