
inherit ITEM;

void create()
{
        set_name( "�ķ���",({"table" }));
        set_weight(30000);
        set_max_encumbrance(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("value", 2000);
                set("long", "����һ�ź�ľ�ķ�����������ż�˫���ӡ�\n" );
                set("no_sell", "���������������������");
                set("no_get","��ľ�ķ����Ǿ�¥�ĲƲ�,�κ��˶���������!");
                set("no_get_from","�Բ��ˣ�Ҳ���ܶ�����Ү��");
        }        
        setup();
}
int is_container() { return 1; }


void init()
{
        add_action("do_look","look");
        add_action("do_eat","eat");
}
int do_look(string arg)
{
        string str1,str2;
        object ob;

        if (!arg)       return 0;
        if (sscanf(arg,"%s %s",str1,str2)!=2)
                return 0;
        if (!id(str1)) return 0;
        ob=present(str2,this_object());
        if (!ob)        return 0;
        write(ob->long());
        return 1;
}
int do_eat(string arg)
{
    object food;
    if (!arg)   return 0;
    food=present(arg,this_object());
    if (!food || !inherits(F_FOOD,food))   return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if( !food->query("food_remaining") )
        return notify_fail( food->name() + "�Ѿ����Թ��ˣ�ֻʣ�¸���"+food->query("unit")+"��\n");
    if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() ){
        write("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
                return 1;
    }
    this_player()->add("food", food->query("food_supply"));
    if( this_player()->is_fighting() ) this_player()->start_busy(2);
    // This allows customization of drinking effect.
    if( food->query("eat_func") ) return 1;
    food->set("value", 0);
    food->add("food_remaining", -1);
    if( !food->query("food_remaining") ){
        message_vision("$N��ʣ�µ�$n�Եøɸɾ�����\n",this_player(),food );
        remove_call_out("dest_food");
        call_out("dest_food",20);
    }else{
        if (stringp(food->query("eat_msg")))
        message_vision(food->query("eat_msg"),this_player(),food );
        else
        message_vision("$N������ӣ�����$nҧ��һ�ڡ�\n",this_player(),food );
    }
    return 1;
}
void dest_food()
{
        foreach (object food in all_inventory()){
                if (food && inherits(F_FOOD,food) && !food->query("food_remaining"))
                        destruct(food);
        }
        message("vision","һ���ϻ������������ʮ�������ذѿյ�������������ת��������¥��\n",environment(this_object()));
}

