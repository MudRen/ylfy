//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�������Ǽ��鷿��
LONG
	);
	set("exits", ([ 
//            "west" : __DIR__"houyuan",
            "northwest" : __DIR__"zoulang4",
            "south" : __DIR__"zoulang6",
            "east" : __DIR__"shufang",
            ]));

	setup();
	replace_program(ROOM);
}
