inherit ITEM;
void create()
{
        set_name(MAG"����"NOR, ({ "xiong zhang","zhang"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������!\n");
                set("unit", "��"); 
                //set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",50000);
                set("zhuyao",11);
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
  return notify_fail("��ö����������ڵ�,��Ը�ʲô����\n");
    
if (me->query("max_neili")>me->query_skill("force",1)*50)
{
 me->add("max_neili",random(3));   
} else {
me->add("max_neili",10+random(30));
}
    
  message_vision(HIY"$N�������Ƴ�����ȥ,�о��������ֵ���������㡣\n"NOR,me);
       destruct(this_object());
       return 1;
}

