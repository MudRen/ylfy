// xu-cloth.c
//
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�Ʋ�����", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
            set("shaolin",1);
                set("armor_prop/armor", 2);
        }
        setup();
}
int query_autoload() { return 1; }