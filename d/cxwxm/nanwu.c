// Room: /d/cxwxm/nanwu.c
// marry 99.8
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short",HIC"南屋"NOR);
         set("long",
"这里便是痴心妄想门的弟子领取本门服装的地方，本门\n"
"弟子不分男女，都可在这里领(ling)到一套弟子服。\n\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gc",
]));
        set("objects", ([
        __DIR__"npc/long" : 1
        ]));

        setup();
}
/*
void init()
{
        object me;
        me=this_player();
        if (wizardp(me)) return 0;
        if (!me->query("jihao",1))
        {
        message_vision(HIC"突然,眼前出现了一大票的人，其中一个人指着$N大叫：\n"NOR
                    CYN"“我想起来了，就是他干的！”\n"NOR
                    HIR"立刻黑压压的一群人提着西瓜刀冲了过来，向$N一阵乱砍！\n"NOR,me);
                me->move("/d/cxwxm/tianye");
                me->unconcious();
        } 
        add_action("do_ling", "ling");
}
*/
int do_ling(string arg)
{
       object me;
       object cloth;
       me=this_player();
              if (me->query("family/family_name") != "痴心妄想门")return notify_fail("龙雨娇说道：“你好象不是本门弟子？”\n");

       if (arg)  return notify_fail("龙雨娇说道：“我这里只有弟子服。”\n");
       if (cloth = present("cloth", me)) return notify_fail("龙雨娇说道：“你不是已经有了吗？”\n");
        message_vision("龙雨娇递给$N一件弟子服。\n",me);
        cloth=new(__DIR__"obj/cloth");
        cloth->move(me);
       return 1; 
}

