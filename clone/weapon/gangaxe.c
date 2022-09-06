// longsword.c 短钢斧
#include <weapon.h>
inherit AXE;
void create()
{
        set_name("短钢斧", ({ "gang axe","axe" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把普通的短钢斧。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N从腰间抽出一把明晃晃的$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰带。\n");
        }
        init_axe(50,2);
        setup();
}
int query_autoload() { return 1; }