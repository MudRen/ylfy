inherit ITEM;
void create()
{
        set_name(HIW"������"NOR, ({ "wuming dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ҩ,��֪����ʲô��!\n");
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
  if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

  if(me->query("id")!=query("zhuren"))
  return notify_fail("�������������������,��Ը�ʲô����\n");
    
me->add("combat_exp",random(5000));

    
  message_vision(HIG"$N����������������ȥ,�о��������������ʲô�仯��\n"NOR,me);
       destruct(this_object());
       return 1;
}

