// /d/emei/liba.c ������ ���
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������������������ǰ��һ���Ͱ�����ʵ�ס��ȥ·����������
�����Ű뿪��(men)�������������һ��Сé���ݡ�
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"maocaowu",
                "north" : __DIR__"taolin", 
		]));
	set("objects", ([ 
	]));

	setup();
	replace_program(ROOM);
}
