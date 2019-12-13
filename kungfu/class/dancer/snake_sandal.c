// snake_sandal.c
#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
       set_name( RED "´©»¨ÉßÓ°Ð¬" NOR, ({ "snake sandals", "sandals" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
                set("unit", "Ë«");
        set("value", 8000);
        set("material", "cloth");
                set("armor_type", "boots");
        set("armor_prop/armor", 2);
        set("armor_prop/dodge", 2);
    }
}
