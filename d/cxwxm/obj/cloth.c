#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG "���ӷ�" NOR, ({ "cloth", "fu" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("long","���ǳ���������Ϊ���������Ƶķ�װ��ûʲô�ر�ġ�\n");
        }
        setup();
}

