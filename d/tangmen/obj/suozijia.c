// suozijia.c ���Ӽ�
//

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("���Ӽ�", ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		  set("icon", "10086");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 50);
        }
        setup();
}

