// jinfeng-xiapi.c
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(MAG "���ϼ��" NOR, ({ "jinfeng xiapi", "cloth", "xiapi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ɫ��˺�ĵ�������磬����������һ�ɵ��������㡣\n");
                set("unit", "��");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}
int query_autoload() { return 1; }
