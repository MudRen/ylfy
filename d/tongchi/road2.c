inherit ROOM;
void create()
{
          set("short", "小道");
        set("long", @LONG
通吃帮虽然简陋，但其自然景象却不容错失。小道四周
都种植各种花草，阵阵清风迎面吹来，好不清爽。这里往北
就是议事厅。
LONG
        );
        set("exits", ([
                       "north" : __DIR__"yishi",
                     "south" : __DIR__"road",
        ]));
        set("objects", ([
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
