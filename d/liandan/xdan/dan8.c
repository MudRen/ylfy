inherit ITEM;
void create()
{
        set_name(HIR"根骨丹"NOR, ({ "gengu dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {       
           set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);
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
  int maxneili,neili;

    neili = me->query("neili");
    maxneili = me->query("max_neili");
    
  if(!id(arg)) return 0;
  if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

  if(me->query("id")==query("value"))
  return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");

  if(me->query("con")>29)
  return notify_fail("跟骨丹只能提高到30，过了就不能吃了。\n");
    
me->add("combat_exp",random(5000));
me->add("con",1);   
message_vision(HIR"$N拿起根骨丹吃了下去,感觉自己的先天根骨增加了一点!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

