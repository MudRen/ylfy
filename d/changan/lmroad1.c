// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "绎道");
    set("long", @LONG
一条青石铺就的驿道向北是古都长安，向东是河南龙门。
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