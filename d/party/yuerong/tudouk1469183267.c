inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����һ����Ȼ�ĺ��ۣ����СС���̴������￿��������Ȼ��������ׯ���Ĺ����£�
�������ϣ����ٹٴ�Ҳ�����������

LONG
);
	set("exits", ([
"west" : "/d/party/yuerong/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

