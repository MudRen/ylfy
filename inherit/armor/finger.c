// finger.c

#include <armor.h>
inherit EQUIP;

varargs void setup(int v)
{
    if( !v && clonep(this_object()) ) return; // 有 v 则为动态装备
    set("armor_type", TYPE_FINGER);
    if( !query("armor_apply/dodge")
    &&  weight() > 3000 )
        set("armor_prop/dodge", - weight() / 3000 );
}
