//marry 8.13
#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIW"���븫"NOR, ({ "axe" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "iron");
                set("long", "���ǳ������������Ƶ��ָ���\n");
                set("wield_msg", "$N�ӱ���γ�һ�����λ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���ڱ��󡣡�\n");
        }
         init_axe(250);
        setup();
}
