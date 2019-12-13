//youtan.c 幽昙仙花
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name( MAG "幽昙仙花" NOR, ({"youtan flower","youtan","flower"}));
        set("unit", "株");
        set("value", 0);
    set("long", "一朵海碗般大的奇花，花瓣碧绿，娇艳奇丽。闻起来有股幽幽的甜香。\n");
        setup();
}
void add_age(object me)
{
    if (me!=environment()) return;
       tell_object(me,MAG+"你忽然觉得身体发生了一些微妙的变化。\n"+NOR);
    if ( ( me->query("mud_age") / 86400) > 5 ){
    if ( ((int)me->query("mud_age") / 86400)  > 5 - me->query("age_modify") )
    me->add("age_modify",-1);
    else
    me->set("age_modify",-((int)me->query("mud_age") / 86400) + 5 );
    }
    me->set_temp("add_age",0);
    me->update_age(1);
    destruct(this_object());
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    if ( me->query_temp("add_age"))  return notify_fail("你要吃什么？\n");
    message_vision(HIG"$N看着那么香甜的"+this_object()->name()+HIG+"，想也不想,一口把"+this_object()->name()+HIG+"吞了!\n" NOR,this_player());
    if (me->query("age")<20){
        tell_object(me,"你吃下一朵又甜又香的"+this_object()->name()+NOR+"。\n");
        destruct(this_object());
        return 1;
     }
     call_out("add_age",10,this_player());
     me->set_temp("add_age",1);
    return 1;
}
void reset(){ }

int query_autoload() { return 1; }