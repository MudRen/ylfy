inherit ITEM;
void create()
{
        set_name(HIG"正气丸"NOR, ({ "zhenqi wan","wan"}));
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
    
me->add("shen",5000000);
 message_vision(HIB"$N拿起正气丸吃了下去,感觉丹田传来一阵阵热意,顿时眼睛射出一股浩然正气!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

