// dating.c
// marry 8.20
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"大厅"NOR);
    set("long", 
        "这里就是痴心妄想门的大厅了。在大厅的正面挂着一块牌\n"
        "匾，威风凛凛的镶着“"HIY"痴 心 妄 想 门"NOR"”几个硕大的金字。牌\n"
        "匾的下方则挂着两幅画，左边一幅为“"HIM"凤"HIG""BLINK"舞"NOR""HIC"九天"NOR"”，而右面一\n"
        "幅却是“"HIR"猛龙"HIW""BLINK"出"NOR""HIB"海"NOR"”。\n\n");
    set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_sleep_room",1);
    set("exits", ([
       "north" : __DIR__"fanting.c",
        "west" : __DIR__"feifeng.c",
        "east" : __DIR__"menglong.c",
       "south" : __DIR__"dayuan.c",
]));
set("objects", ([
                __DIR__"npc/mylover.c" : 1,
        ]));

    setup();
    //"/clone/board/cxwxm_b.c"->foo();
}
/*
void init()
{
        int n;
        object me;
        me=this_player();
        n = (int)me->query("combat_exp");
        if (wizardp(me)) return 0;
        if ((me->query("family/family_name") == "痴心妄想门")&&((int)me->query("cps")>= 20) && ((int)me->query("kar")>= 25)&&(n>=100000))
        {
         me->set("jihao",1);
         return 0;
        } 
        if (!me->query("jihao",1))
        {
        message_vision(HIC"突然,眼前出现了一大票的人，其中一个人指着$N大叫：\n"NOR
                    CYN"“我想起来了，就是他干的！”\n"NOR
                    HIR"立刻黑压压的一群人提着西瓜刀冲了过来，向$N一阵乱砍！\n"NOR,me);
                me->move("/d/cxwxm/tianye");
                me->unconcious();
        } 
}
*/
