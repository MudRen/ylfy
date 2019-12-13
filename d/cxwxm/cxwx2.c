// Room: /d/cxwxm/cxwx2.c
// This is a room made by roommaker. write by Xyx.

#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "后门前");
        set("long", @LONG
你一出门，进入你眼帘的便是蜿蜒的大山，这里三面环山，几条小路通
向山中，没有什么特别的景致，不过喊叫的声音似乎更大了一些。

LONG
);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 2,
  __DIR__"npc/chuhuan" : 1,
]));
        set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"xiwuchang",
  "northup" : __DIR__"xiwuchang2",
  "southup" : __DIR__"xiwuchang3",
  "west" : __DIR__"houmen",
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
