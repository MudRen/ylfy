//bye enter

inherit ROOM;

void create()
{
        set("short", "���Ⱦ�ͷ");
	set("long", @LONG
���������ȵľ�ͷ��������ȥ�Ǻô��һ��������ǰ���и�
Сͤ�������ֵܻ�������ܡ�
LONG
	);
	set("exits", ([ 
            "north" : __DIR__"tingzi",
            "southeast" : __DIR__"zoulang7",
            "south" : __DIR__"houyuan",
            "southwest" : __DIR__"zoulang3",
            ]));

	setup();
	replace_program(ROOM);
}
