// bu-shoes.c example shoes

#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name( GRN "��Ь" NOR, ({ "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("value", 50);
		  set("icon", "10004");
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 2);
                set("wear_msg","$N����һ˫$n��\n");
                set("remove_msg","$N��$n����������\n");
        }
		setup();
}

int query_autoload() { return 1; }