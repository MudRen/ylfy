inherit ITEM;
void create()
{
        set_name(HIG"������"NOR, ({ "jingfeng wan","wan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
       else {   
                set("unit", "��"); 
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
  return notify_fail("��õ�����������,��Ը�ʲô����\n");
    
me->add("combat_exp",random(5000));
me->set_skill("dodge",me->query_skill("dodge",1)+1);
  message_vision(HIY"$N���𾪷��������ȥ,�о����Ṧ���о���������!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}


