// hands.c

#include <armor.h>
inherit EQUIP;

varargs void setup(int v)
{
    if( !v && clonep(this_object()) ) return; // �� v ��Ϊ��̬װ��
    set("armor_type", TYPE_HANDS);
    if( !query("armor_apply/dodge")
    &&  weight() > 3000 )
        set("armor_prop/dodge", - weight() / 3000 );
}
