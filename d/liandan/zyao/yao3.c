inherit ITEM;
void create()
{
        set_name(MAG"茯苓"NOR, ({ "fu ling","ling"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗茯苓!\n");
                set("unit", "颗"); 
                //set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
                set("zhuyao",3);
                set("value",50000);
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

  if(me->query("id")!=query("zhuren"))
  return notify_fail("这棵东西不是你挖的,你吃个什么劲。\n");
    
    me->add("combat_exp",3000);  
    
  message_vision(HIY"$N拿起茯苓吃了下去,感觉经验值最大值增加了3000点。\n"NOR,me);
       destruct(this_object());
       return 1;
}

