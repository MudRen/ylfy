inherit ITEM;
void create()
{
        set_name(HIC"�湦��"NOR, ({ "qigong wan","wan"}));
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
    
   if(!me->query("zjbygbz_ssl"))
{
    write("�㻹ûѧ�Ĵ��湦��û�취�ԡ�!\n");
return 1;
}

me->add("combat_exp",random(5000));
if (me->query("zjbygbz_ssl")=="zhanshen")
me->set_skill("zhanshen-lu",me->query_skill("zhanshen-lu",1)+1);
if (me->query("zjbygbz_ssl")=="daoxin")
me->set_skill("daoxin-zhongmo",me->query_skill("daoxin-zhongmo",1)+1);
  message_vision(HIB"$N�����湦�������ȥ,�о����湦���˽����������!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}


