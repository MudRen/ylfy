inherit ITEM;
void create()
{
        set_name(HIC"奇功丸"NOR, ({ "qigong wan","wan"}));
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

  if(me->query("id")==query("value"))
  return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");
    
   if(!me->query("zjbygbz_ssl"))
{
    write("你还没学四大奇功呢没办法吃。!\n");
return 1;
}

me->add("combat_exp",random(5000));
if (me->query("zjbygbz_ssl")=="zhanshen")
me->set_skill("zhanshen-lu",me->query_skill("zhanshen-lu",1)+1);
if (me->query("zjbygbz_ssl")=="daoxin")
me->set_skill("daoxin-zhongmo",me->query_skill("daoxin-zhongmo",1)+1);
  message_vision(HIB"$N拿起奇功丸吃了下去,感觉对奇功的了解更加清晰了!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}


