// gangdao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�̵�", ({ "blade" }));
        set_weight(7000);
                set("flag",2);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����ɵĶ̵�������͸��һ����ɱ֮����\n");
                set("value", 5);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
       init_blade(200,2);
        setup();
}

