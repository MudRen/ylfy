// cloth.c
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("Ѳ����", ({ "xunbu fu","fu","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
		set("value",1000);
                set("armor_prop/armor", 10);
        }
        setup();
}
int query_autoload() { return 1; }