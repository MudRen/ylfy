// fan.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"���ݳ���"NOR, ({ "fan" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�̿ɿڵĳ�����\n");
                set("unit", "��");
                   set("no_get",1); 
                   set("no_give",1); 
                   //set("no_drop",1); 
                set("value", 0);
                set("remaining",5);
                set("food_supply", 100);
                set("water_supply", 100);
        }
    setup();
}

void init()
{
        add_action("do_chi", "chi");
}


int do_chi(string arg)
{

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food")  
       >= (int)this_player()->max_food_capacity() && 
          (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )   return notify_fail("���Ѿ���̫���ˣ���Ҳ�Բ����ˡ�\n");

    set("value", 0);
    this_player()->add("food", (int)query("food_supply"));
    this_player()->add("water", (int)query("water_supply"));   
    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
        if ( query("remaining") )
        {
                 message_vision("$N�������ݳ��������̻��ʵس�������\n", this_player());
        } 
        else 
        { 
                 message_vision("$N����������һ�ӣ�Ĩ��Ĩ�죬��ҡ��ڵ��߿��ˡ� \n",this_player());
                destruct(this_object());
        }

        return 1;
}

