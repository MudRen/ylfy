// hongjuan.c
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name( RED "红手绢" NOR , ({ "hong juan", "juan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块红手绢，上面写着一首短词：\n"
                            "四张机，鸳鸯织就欲双飞。\n"
                            "可怜未老头先白，春波碧草。\n"
                            "晓寒深处，相对浴红衣。\n");
                set("unit", "块");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一块$n扎在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);
        }
        setup();
}

int query_autoload() { return 1; }