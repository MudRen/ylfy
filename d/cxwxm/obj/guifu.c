//marry 8.13
#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIR"��"NOR, ({ "guifu","axe" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "blacksteel");
                set("long", "�����ߴ�޴���ò�����ȴ�ǳ��������ſ�ɽʼ�����Ϲ�\n"
"�������ɵĹ���\n");
                set("wield_msg", "$N�ӱ���γ�һ�����λ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���ڱ��󡣡�\n");
        }
//marry 8.13
{       set("no_get",1);
        set("no_drop",1);
        set("no_give",1);
}

        init_axe(900);
        setup();
}

