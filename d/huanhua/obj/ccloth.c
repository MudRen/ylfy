

#include <ansi.h>

#include <armor.h>



inherit CLOTH;



void create()

{

        set_name(HIB "��ɫ��װ" NOR, ({"cloth"}) );

    set_weight(3000);

    if( clonep() )

       set_default_object(__FILE__);

    else {

        set("unit", "��");

                set("long", "һ������ͨͨ����ɫ��װ��\n");

        set("material", "cloth");

        set("armor_prop/armor", 2);

    }

    setup();

}

