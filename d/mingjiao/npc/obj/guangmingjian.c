// guangmingjian.c 

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("������", ({ "guangming jian", "jian" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("icon", "10035");
                set("long", "����һ�����̵��ӵľ��ֽ���������š��������ڣ������������˸��֡�\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(40);
        setup();
}

int query_autoload() { return 1; }