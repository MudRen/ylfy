//bye enter

inherit ROOM;

void create()
{
        set("short", "����С��");
	set("long", @LONG
���������ĵ�С���ϡ��������ﻨ�㣬�ʵ��׷ɣ���ɫ���ˣ���
���з·������������ζ����
LONG
	);

        set("outdoors","chengdu");
	set("exits", ([ 
            "north" : __DIR__"xiaodao1",
            ]));

	setup();
	replace_program(ROOM);
}
