//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩���������������ס����
LONG
	);
	set("exits", ([ 
//            "west" : __DIR__"houyuan",
            "north" : __DIR__"zoulang7",
            "south" : __DIR__"zoulang5",
            "east" : __DIR__"fang4",
            ]));

	setup();
	replace_program(ROOM);
}
