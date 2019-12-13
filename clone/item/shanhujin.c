//shanyu-jin 珊瑚金
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIM"珊瑚金"NOR, ({"shanhu jin", "shanhu","jin" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIM"这是一根在海底沉积千万年而成的珊瑚金，日积月累，坚硬无比，是锻造兵器的上好材料。\n");
                set("no_sell", 1);
                set("value", 10000);
                //set("no_drop", "这么珍贵的宝物，你可不能随意丢弃！\n");
                set("can_make", "all");
                set("not_make", ({ "鞭", "锤", "护甲","战衣", "指套", "腰带","靴子" }));
                set("rigidity",200+random(30)); //设置材料硬度，也即武器硬度
                set("material_attrib", "gold");
                set("power_point", 190+random(30)); //做成后的jiali大小
                set("rate", 3); //设置材料等级
        }

        setup();
}
