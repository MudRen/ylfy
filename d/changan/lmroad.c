// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "���");
    set("long", @LONG
һ����ʯ�̾͵�������ϱ����죬������������ľ��
LONG
);
        set("outdoors","changan");
    set("exits", ([
		"north":__DIR__"ca13",
       "south":__DIR__"lmroad1",
]));
    setup();
    replace_program(ROOM);
}