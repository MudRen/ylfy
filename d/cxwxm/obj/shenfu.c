//marry 8.13
#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIB"������"NOR, ({ "axe" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "iron");
                set("long", "���ǳ��������ű������ǿ�ɽ�������Ϲ��������ɡ�\n");
                set("wield_msg", "$N�ӱ���γ�һ���λ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���ڱ��󡣡�\n");
        }
{       set("no_get",1);
        set("no_drop",1);
        set("no_give",1);
}
        init_axe(900);
        setup();
}
