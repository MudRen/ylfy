// Room: /d/heimuya/zhaoze/fongdian.c

inherit ROOM;

void create()
{
        set("short", "峰巅");
        set("long", @LONG
那山峰顶上是块平地，开垦成二十来亩山田，种着禾稻，一柄锄头抛
在田边。一条长藤就绑在崖边的一块大石上。
LONG
);
        set("exits", ([ 
  "north" : __DIR__"shiliang",
]));
        set("item_desc", ([
        "长藤" : "你可以顺着它爬下山去。\n",
]));
    set("objects", ([
        __DIR__"npc/nongfu" : 1,
    ]));


        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="长藤") return notify_fail("你要爬什么？\n");
            message("vision", me->name() + "顺着长藤爬了下去。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"shanbian1");
            message_vision("$N心惊胆战地爬了下来。\n", me);
        return 1;
}
int valid_leave(object me, string dir)
{
        object ob=present("nong fu", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "north" ) {
                    say("农夫对"+me->name()+"喝道：请留步。\n");
                    return notify_fail("农夫喝道：这位" + RANK_D->query_respect(me) + "请止步。\n");
            }
        }
        return ::valid_leave(me, dir);
}

