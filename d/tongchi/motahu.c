inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "莫塔湖");
        set("long", @LONG
“莫塔湖”，深不可测，冰冷澈骨，加上飞瀑往下冲，故名虽是湖，
而波涛汹涌非常，比之长汪三峡水势，有过之而无不及。
LONG
);
        set("exits", ([ 
  "south" : __DIR__"?",
]));

        set("item_desc", ([
        "飞瀑" : "你可以试着跳过去。\n",
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
    if( !arg || arg!="飞瀑") return notify_fail("你要跳什么？\n");
            message("vision", me->name() + "顺着飞瀑跳了过去。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"damen");
            message_vision("$N气喘吁吁地跳了过来。\n", me);
        return 1;
}
