// hsroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ�������Լ�ɼ������ݳǵĳ�ǽ������������·��
��ͨ��ɽ�
LONG );
        set("outdoors", "wudang");
	set("exits", ([
        "east"     : __DIR__"hsroad1",
		"northwest" : __DIR__"hsroad3",
		"northeast" : "/d/huashan/jzroad1",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

