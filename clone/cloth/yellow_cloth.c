// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"����"NOR, ({ "yellow cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����ɫ�ĳ����������ż�ֻ�컨������������һ�ɵ��㡣\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}
int query_autoload() { return 1; }