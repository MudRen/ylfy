// ----/d/obj/tangyuan.c ----
inherit ITEM;
void create()
{
        set_name(HIW"��Բ"NOR, ({ "tang yuan",}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��"+HIY+"������"+NOR+"��"+HIR+"������"+NOR+"��"+HIW+"��Բ"+NOR+"����˵�����������ģ���һ�룬���Ժþö�������\n");
                set("unit", "��");
                set("value",0);
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
  int food,water;
    food = me->query("food");
    water = me->query("water");
    
  if(!id(arg)) return 0;
  if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

    if(food < (int)me->max_food_capacity() * 5 && food < 5000) me->add("food", 1000);
    else me->add("food",(int)me->max_food_capacity() / 100);
     
    if(food < (int)me->max_water_capacity() * 5 && water < 5000) me->add("water", 1000);
    else me->add("water",(int)me->max_water_capacity() / 100);

    if(me->is_fighting()) me->start_busy(2);
       message_vision(CYN"$N�������������̻��ʵذ���Բ�������ˡ�\n"NOR,me);
       destruct(this_object());
       return 1;
}

int query_autoload() { return 1; }