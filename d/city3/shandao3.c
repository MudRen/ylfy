//bye enter

inherit ROOM;

void create()
{
        set("short", "ɽ����");
	set("long", @LONG
������һ����ɽ������ǰ������ں����ģ������˵ģ���
�ǲ�Ҫ��ȥ�ĺá�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southdown" : __DIR__"shandao2",
                "north" : __DIR__"shandong0",
	]));

	setup();
	replace_program(ROOM);
}

