// fengguan.c
#include <armor.h>
inherit HEAD;
void create()
{
        set_name(HIY "���" NOR, ({ "feng guan", "guan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "silk");
                set("unit", "��");
                set("long", "����һ���ý�˿������֯�ɵķ�ڡ�\n");
                set("value", 1500);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
       }
        setup();
}

int query_autoload() { return 1; }