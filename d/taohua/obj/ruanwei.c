
#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name(BLK "��⬼�" NOR, ({ "ruan wei jia","ruan","wei","jia", }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
	set("icon", "10088");
        set("armor_type", "cloth");
        set("no_sell", 1);
            set("armor_prop/dodge", 10);
        set("armor_prop/armor", 300);
    }
}
