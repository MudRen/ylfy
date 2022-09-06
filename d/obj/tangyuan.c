// ----/d/obj/tangyuan.c ----
inherit ITEM;
void create()
{
        set_name(HIW"汤圆"NOR, ({ "tang yuan",}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗"+HIY+"香喷喷"+NOR+"，"+HIR+"热辣辣"+NOR+"的"+HIW+"汤圆"+NOR+"。据说是由仙人做的，吃一碗，可以好久都不饿。\n");
                set("unit", "碗");
                set("value",0);
        }
    setup();
}
void init()
{
    if (environment()==this_player())
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me = this_player();
  int food,water;
    food = me->query("food");
    water = me->query("water");
    
  if(!id(arg)) return 0;
  if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

    if(food < (int)me->max_food_capacity() * 5 && food < 5000) me->add("food", 1000);
    else me->add("food",(int)me->max_food_capacity() / 100);
     
    if(food < (int)me->max_water_capacity() * 5 && water < 5000) me->add("water", 1000);
    else me->add("water",(int)me->max_water_capacity() / 100);

    if(me->is_fighting()) me->start_busy(2);
       message_vision(CYN"$N端起碗来，狼吞虎咽地把汤圆连汤吞了。\n"NOR,me);
       destruct(this_object());
       return 1;
}

int query_autoload() { return 1; }