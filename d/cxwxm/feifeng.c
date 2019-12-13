// Room: /d/cxwxm/feifeng.c
// This is a room made by roommaker. write by Xyx.

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "飞凤轩");
        set("long", @LONG
这是本门门主的会客室，但看起来却好似书房。靠墙摆放着一排书架,
在书架上整齐的摆着一些书。屋中央放着个看起来有些古老的檀木小桌，上
面有一把精致的小壶和几个玲珑的小茶杯。

LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dating",
  "west" : __DIR__"feifeng2.c",
]));
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/feng" : 1,
  __DIR__"npc/yahuan" : 2,
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
}
*/