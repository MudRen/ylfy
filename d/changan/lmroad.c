// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "绎道");
    set("long", @LONG
一条青石铺就的驿道向南北延伸，道旁种满了树木。
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