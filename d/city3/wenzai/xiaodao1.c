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
            "south" : __DIR__"xiaodao",
            "northeast" : __DIR__"xiaoyuan"
            ]));

	setup();
	replace_program(ROOM);
}
