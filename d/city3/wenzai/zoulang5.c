//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�������������ĵ�ס����
LONG
	);
	set("exits", ([ 
//           "west" : __DIR__"houyuan",
            "north" : __DIR__"zoulang6",
            "southwest" : __DIR__"dating",
            "east" : __DIR__"fang3",
            ]));

	setup();
	replace_program(ROOM);
}
