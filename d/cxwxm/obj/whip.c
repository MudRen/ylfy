#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(BLU"���ı�"NOR, ({ "whip" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "iron");
                set("long", "���ǳ������������ƵĶ̱ޡ�\n");
                set("wield_msg", "$N���һ����ڵ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n�������䡣��\n");
        }

         init_whip(200);
        setup();
}
