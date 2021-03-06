// fan.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"扬州炒饭"NOR, ({ "fan" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘可口的炒饭。\n");
                set("unit", "盘");
                   set("no_get",1); 
                   set("no_give",1); 
                   //set("no_drop",1); 
                set("value", 0);
                set("remaining",5);
                set("food_supply", 100);
                set("water_supply", 100);
        }
    setup();
}

void init()
{
        add_action("do_chi", "chi");
}


int do_chi(string arg)
{

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("food")  
       >= (int)this_player()->max_food_capacity() && 
          (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )   return notify_fail("你已经吃太饱了，再也吃不下了。\n");

    set("value", 0);
    this_player()->add("food", (int)query("food_supply"));
    this_player()->add("water", (int)query("water_supply"));   
    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
        if ( query("remaining") )
        {
                 message_vision("$N端起扬州炒饭，狼吞虎咽地吃起来。\n", this_player());
        } 
        else 
        { 
                 message_vision("$N将盘子往后一扔，抹了抹嘴，大摇大摆的走开了。 \n",this_player());
                destruct(this_object());
        }

        return 1;
}

