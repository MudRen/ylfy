//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�����������ϴ��ס����
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "north" : __DIR__"zoulang2",
            "southeast" : __DIR__"dating",
            "west" : __DIR__"fang1",
            ]));

	setup();
	replace_program(ROOM);
}
