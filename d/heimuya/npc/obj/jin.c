// cloth.c
//
// This is the basic equip for players just login.
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("��˿��", ({ "jin" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("icon", "10088");
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}
int query_autoload() { return 1; }