inherit ROOM;

void create()
{
	set("short", "��ڣ");
	set("long", @LONG
��ʯ�ϡ���ڣ����������֮�ԣ��������������С��ʯ�̣�
����ħ������ܼ��޵�����£������˹��
�غ���Ⱥ�����֣��������������౯�򣡡�

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie2.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

