// Room: houyuan.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
厅后是个院子，院中花卉暗香浮动，但见东厢房的窗子中
透出灯火之光，火苗闪烁不已，似乎有人影晃动，好象刚有人
从此走过！
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xiaoting",
  "west" : __DIR__"xxiangfang",
  "north" : __DIR__"beixiangfang.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

