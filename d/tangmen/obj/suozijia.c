// suozijia.c Ëö×Ó¼×
//

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Ëø×Ó¼×", ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		  set("icon", "10086");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 50);
        }
        setup();
}

