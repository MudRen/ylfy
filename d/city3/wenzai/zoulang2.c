//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩����������������ס����
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
            "west" : __DIR__"fang2",
            ]));

	setup();
	replace_program(ROOM);
}
