//chahua11.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
set_name(HIR"红妆"HIW"素裹"NOR, ({"cha hua","cha hua 11", "hua"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", 
"一株茶花，白色花瓣上似乎洒了些红斑。\n");
                set("value", 5000);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}


int query_autoload() { return 1; }
