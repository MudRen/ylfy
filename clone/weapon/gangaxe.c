// longsword.c �̸ָ�
#include <weapon.h>
inherit AXE;
void create()
{
        set_name("�̸ָ�", ({ "gang axe","axe" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ķ̸ָ���\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����λε�$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���������\n");
        }
        init_axe(50,2);
        setup();
}
int query_autoload() { return 1; }