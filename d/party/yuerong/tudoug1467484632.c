inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�������µ�У��֮���Ѿ������˺�ѹѹ����Ⱥ���������̳ɵľ޴�᳡֮�ϼ��ž޴������̨��
��̨���Ա������Ÿ��Ÿ��ɵĽ������ӣ�ÿ���˶������˷ܵ���ɫԾԾ���Ե����ӡ�

LONG
);
	set("exits", ([
"south" : "/d/party/yuerong/tudoub1466848465.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

