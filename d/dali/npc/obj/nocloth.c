// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIR "��Ѫɴ��" NOR, ({ "shayi" }) ); 
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������Ѫ��ɴ��\n");
                set("material", "cloth");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        setup();
}

int query_autoload() { return 1; }