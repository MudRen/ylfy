
inherit ROOM;
void create()
{
    set("short", "甬道");
    set("long", @LONG
这是一道梯级。下了梯级再走十多丈路，前面豁然开朗，竟是一大片平地。
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ 
  "down" : __DIR__"room40",
]));
    setup();
    replace_program(ROOM);
}
