// /d/cxwxm/shandong.c
// marry 99.8
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short","山洞");
       set("long", @LONG
原来这下面是一个山洞，这里四周漆黑一片，阴冷潮湿，你向四周摸了摸，似乎摸不
到石壁。一阵寒风吹来，冷得你直打寒战。
LONG
     );
       
        set("exits", ([
                "northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));
        setup();
}

void init()
{
        object me;
        int jing, jing_cost, n ,v;

        me = this_player();
        n = (int)me->query("combat_exp");
        v = (int)me->query("dex");
        jing = me->query("jing");
        jing_cost = (me->query("chulu") * 5);

        if(jing < jing_cost)
                me->unconcious();
        me->add("jing", -jing_cost);

        if (me->query("chulu") >= 10)
        {
message_vision(HIC"$N一边胡思乱想，一边乱走，忽然发现眼前一亮，已经来到了一个世外桃源。\n"NOR            WHT"但是$N终于因为体力不支，昏死了过去！\n"NOR,me);

                me->move("/d/cxwxm/cxwx");
                me->set("chulu",0);
                me->set("jihao",1);
                me->unconcious();
                return;
        }  
        if ((me->query("chulu") <= -10)||(!me->query_temp("jihao")))
        {
                message_vision(WHT"$N一不小心掉入了一条暗河。\n"NOR,me);
                me->move("/d/cxwxm/anhe");
                me->set("chulu",0);
                if(userp(me))
                me->unconcious();
                return ;
        }

   if (((int)me->query("str") >= 15) && (((int)me->query("kar")) >= 25)&& (n>10000000||random(v)>20))        { 
         me->add("chulu",1); 
         }
        else 
        {
         me->add("chulu",-1); 
        }
}
