// long-sword.c 长剑
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("竹剑", ({ "zhu jian","sword", "jian" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
		   set("icon", "10002");
                set("long", "这是一柄练剑用的竹剑。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(10,2);
        setup();
}
int wield()
{
    if (::wield()){
                this_player()->add("int", 1000000);
				this_player()->add("max_neili", 1000000000);
                return 1;
    }else
    return 0;
}
int unequip()
{
    if (::unequip()){
                this_player()->add("int", -1000000);
				this_player()->add("max_neili", -1000000000);
                return 1;
    }else
    return 0;
}
int hit_ob(object me,object victim,int damage_bonus)
{
    victim->start_busy(600);
    return damage_bonus;
}

int query_autoload() { return 1; }