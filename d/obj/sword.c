// long-sword.c ����
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("��", ({ "zhu jian","sword", "jian" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		   set("icon", "10002");
                set("long", "����һ�������õ��񽣡�\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(10,2);
        setup();
}
int wield()
{
    if (::wield()){
                this_player()->add("int", 1000000);
				this_player()->add("max_neili", 1000000000);
                return 1;
    }else
    return 0;
}
int unequip()
{
    if (::unequip()){
                this_player()->add("int", -1000000);
				this_player()->add("max_neili", -1000000000);
                return 1;
    }else
    return 0;
}
int hit_ob(object me,object victim,int damage_bonus)
{
    victim->start_busy(600);
    return damage_bonus;
}

int query_autoload() { return 1; }