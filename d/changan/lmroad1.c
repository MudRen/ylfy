// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "���");
    set("long", @LONG
һ����ʯ�̾͵�������ǹŶ����������Ǻ������š�
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "east":"/d/longmen/lukou",
		"north":__DIR__"lmroad",
]));
    setup();
    replace_program(ROOM);
}