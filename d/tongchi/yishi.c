inherit ROOM;
int do_jump(string arg);
void create()
{
          set("short", "议事厅");
        set("long", @LONG
这里就是通吃帮的议事厅，平常有什么事，大家都会聚在这里
讨论，以找出解决的方法。正中摆放着一张大椅，两旁则是各三
张椅子。厅的中上方放着一块扁(bian),上书［议事厅］。
LONG
        );
        set("exits", ([
                  "north" : __DIR__"tianjin",
                  "south" : __DIR__"road2",
                    "west" : __DIR__"jiujv",
                     "east" : __DIR__"dujv",
        ]));
        set("item_desc", ([
          "bian" : "你可以试着jump。\n",
        ]));
        set("objects", ([
        __DIR__"npc/ouyang" : 1,
        ]));
        setup();
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="bian") return notify_fail("你要跳什么？\n");
            message("vision", me->name() + "顺着扁跳了上去。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"mishi");
            message_vision("$N气喘吁吁地跳了上来。\n", me);
        return 1;
}
