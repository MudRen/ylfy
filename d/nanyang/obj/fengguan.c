// fengguan.c
#include <armor.h>
inherit HEAD;
void create()
{
        set_name(HIY "凤冠" NOR, ({ "feng guan", "guan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "silk");
                set("unit", "顶");
                set("long", "这是一顶用金丝和珍珠织成的凤冠。\n");
                set("value", 1500);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
       }
        setup();
}

int query_autoload() { return 1; }