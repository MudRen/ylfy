inherit ROOM;
int do_move(string arg);
void create()
{
        set("short", "通吃房");
        set("long", @LONG
这里是通吃帮帮主杨小邪的房间 ，一进房间就被房间里的
清新脱俗的布置所吸引住了，房间的中间放着一张桌子，墙上
挂着一张画，画中的人正是杨小邪，此画画的栩栩如生，大概
是出自当今一代名家之手。
LONG
        );
        set("outdoors", "huapu");
        set("exits", ([
                 "south" : __DIR__"tianjin",
                  "west" : __DIR__"sleep_room2",
                  "north" : __DIR__"huayuan",
        ]));
        set("objects", ([
        __DIR__"npc/xiaoxie" : 1,
        __DIR__"npc/xiaoqi" : 1,
        ]));
           set("item_desc", ([
    "画" : "这张画上画的正是杨小邪，这张画似乎可以移动。\n",
           ]));
        setup();
        set("he",1);
}
void init()
{
        add_action("do_move", "move");
}
int do_move(string arg)
{
  object me,sword,flower;
        me = this_player();
        if( !arg || arg=="" ) return 0;
     if( arg=="画" )
        {
                if ((me->query("family/master_id") !="xiao qi") &&
                        objectp(present("xiao qi", environment(me))))
                {
                        return notify_fail(
"小七喝道：这位" + RANK_D->query_respect(me) + "，你想偷东西吗？要先过我这关。\n");
                        return 1;
                }
                if (!query("had_sword"))
                {
                        message_vision(
"$N把画移到了一边,发现了一个锦盒。\n", this_player());
                        flower = new(__DIR__"obj/flower");
               sword=new(__DIR__"obj/he");
            flower->move(sword);
                      sword->move(me);
message("rumor", HIM"〖英雄传言〗"NOR+"："+HIR"听说"HIW+this_player()->query("name")+NOR HIB"拿到传说中的....."MAG"风林花"HIB"了!\n"NOR, users());
                        set("had_sword", 1);
                        return 1;
}
                message_vision(
"$N把画移到了一边，才发现里面的东西已经没了...。\n", this_player());
                return 1;
}
        return 0;

}
