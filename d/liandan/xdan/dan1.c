inherit ITEM;
void create()
{
        set_name(HIW"Ѫ����"NOR, ({ "xueqi dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ѫ����,��֪����ʲô��!\n");
                set("unit", "��"); 
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
  return notify_fail("���Ѫ��������������,��Ը�ʲô����\n");
    
		me->add("combat_exp",random(5000));
 
//����
        me->set("max_jingli",me->query("max_jingli"));
        me->set("jingli",me->query("max_jingli"));
//����
        me->set("max_jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
//����
        me->set("max_neili",me->query("max_neili"));
        me->set("neili",me->query("max_neili"));
//��Ѫ
        me->set("max_qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));    
  message_vision(HIR"$N����Ѫ����������ȥ,�о�ȫ��������!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

