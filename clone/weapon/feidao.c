// feihuangshi.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
      set_name("飞刀", ({ "fei dao", "dao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一把,只有半寸来长的小刀。\n");
                set("unit", "扎");
                set("base_unit", "把");
                set("base_weight", 200);
                set("value",100);
                set("damage", 10);       //Here the damage=int_throwing, added by King
        }
        set_amount(1);
        init_throwing(30,2);
        setup();
}
void set_amount(int amount)
{
    if (amount>500)  amount=500;
    ::set_amount(amount);
}

int query_autoload() { return 1; }