inherit ROOM;

void create()
{
	set("short", "��ħ������");
	set("long", @LONG
����һ���ħ����������������˸��ָ����ĹŶ������൱ֵǮ�������ǽ�̻Ի������ױ�ʵ����̫�����˴�Ҷ��ǳ�������������Ϊֻ����������ܵõ�����
��
��

LONG
);
	set("exits", ([
"west" : "/d/party/emcity/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "emcity");
	
	setup();
}

