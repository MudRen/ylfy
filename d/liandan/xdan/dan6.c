inherit ITEM;
void create()
{
        set_name(HIR"������"NOR, ({ "bili dan","dan"}));
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
  if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

  if(me->query("id")==query("value"))
  return notify_fail("��õ�����������,��Ը�ʲô����\n");
  if(me->query("str")>29)
  return notify_fail("������ֻ����ߵ�30�����˾Ͳ��ܳ��ˡ�\n");
    
me->add("combat_exp",random(5000));
me->add("str",1);   
message_vision(HIR"$N���������������ȥ,�о��Լ����������������һ��!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

