inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
һ�����������Ĺ㳡
��Χ������ʮ�˰����
���ܻ��кܶ�÷��׮��ľ��
�ǹܶ�Ա��������ϰ����

LONG
);
	set("exits", ([
"north" : "/d/party/cg/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "cg");
	
	setup();
}

