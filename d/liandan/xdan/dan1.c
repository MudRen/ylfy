inherit ITEM;
void create()
{
        set_name(HIW"血气丹"NOR, ({ "xueqi dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗血气丹,不知道有什么用!\n");
                set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",1000000);

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
    

  if(me->query("id")== query("value"))
  return notify_fail("这棵血气丹不是你练的,你吃个什么劲。\n");
    
		me->add("combat_exp",random(5000));
 
//精力
        me->set("max_jingli",me->query("max_jingli"));
        me->set("jingli",me->query("max_jingli"));
//精神
        me->set("max_jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
//内力
        me->set("max_neili",me->query("max_neili"));
        me->set("neili",me->query("max_neili"));
//气血
        me->set("max_qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));    
  message_vision(HIR"$N拿起血气丹吃了下去,感觉全身精力充沛!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

