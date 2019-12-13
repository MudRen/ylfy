// caoxie.c 草鞋
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
        set_name("草鞋", ({ "sandals", "cao xie", "xie" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "双");
		set("icon", "10003");
                set("long", "这是一双草编的草鞋，用以保护足部。\n");
                set("value", 100);
                set("armor_prop/dodge", 2);
        }
        setup();
}
int query_autoload() { return 1; }	
