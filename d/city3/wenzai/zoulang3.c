//bye enter

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩���������и�������
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "northeast" : __DIR__"zoulang4",
            "south" : __DIR__"zoulang2",
            "west" : __DIR__"chufang",
            ]));

	setup();
	replace_program(ROOM);
}
