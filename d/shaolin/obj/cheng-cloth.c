// cheng-cloth.c
//
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("��ߺڲ�����", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_sell",1);
        set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
int query_autoload() { return 1; }