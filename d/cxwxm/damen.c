// Room: /d/cxwxm/damen.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", HIC"大门"NOR);
        set("long",
    "这就是【痴心妄想门】的大门。若不是门口的牌匾，一尺多高的门槛\n"
"让人一看就会以为这只不过是一般的豪宅。但门内莫名的寂静更令人毛骨\n"
"悚然。\n\n"
);
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"cxwx",
        "east" : __DIR__"gc",
]));

        setup();
}
void init()
{
        int n;
        object me;
        me=this_player();
        n = (int)me->query("combat_exp");
        if ((me->query("family/family_name") == "痴心妄想门"))
         {
        if  (((int)me->query("dex") < 20) || ((int)me->query("kar")< 25)||(n<100000))
         {
         message_vision(HIR"由于$N做贼心虚，被门槛一拌，啊的一声跌倒在地。\n"NOR,me);
         me->delete("jihao");
          }
         else
         {
         me->set("jihao",1);
          }
         }
         return;
}


