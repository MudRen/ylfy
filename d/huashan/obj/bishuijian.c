// bishuijian.c
// for ����ɺ
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("��ˮ��", ({ "bishuijian", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ڶϽ������ı�������������ɺʮ��������ʱ��\n"
                "����Ⱥ�͸�������������ġ�\n");
                set("value", 8000);
                set("flag",2);
                set("material", "steel");
        set("weapon_prop/personality", 15);
                set("wield_msg", "$N��ৡ���һ�����һ������������$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(35,2);
        setup();
}
int query_autoload() { return 1; }