// tielianzi.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
        set_name("������", ({ "tie lianzi", "lianzi", "zi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������Ƶ�����״������\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 90);
                set("flag",2);
              set("value",300);
                set("damage", 5);       //Here the damage=int_throwing, added by King
        }
        set_amount(1);
        init_throwing(5,2);
        setup();
}
void set_amount(int amount)
{
    if (amount>500)  amount=500;
    ::set_amount(amount);
}

int query_autoload() { return 1; }