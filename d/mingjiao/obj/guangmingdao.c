// guangmingdao.c 

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("������", ({ "guangming dao", "dao" }));
        set_weight(6000);
        set("unique", 1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����̵��ӵľ������ɵĸֵ����������λε��ƺ���һ��Ѫɫ��\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
        init_blade(40);
        setup();
}
