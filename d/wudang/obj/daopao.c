// daopao.c
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����", ({
 "dao pao","pao","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("value",100);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
int query_autoload() { return 1; }