// dadao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(RED "Ѫ��" NOR, ({ "blade","wolf blade" }));
        set_weight(1000);
                if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED "����������͸����⣬���˿�������һ����\n" NOR);
                set("value", 0);
                set("flag",2);
                                set("material", "steel");
                set("wield_msg", RED "$N���һ��Ѫ�ǣ���ʱ$N˫Ŀ���࣬���Ϸ�������һ�������졣\n" NOR);
                set("unwield_msg", RED "$N�����е�$n��ر���\n" NOR);
        }
        init_blade(random(1000)+50,1);
        setup();
}
/*
int wield()
{
    if (::wield()){
            environment()->set("attitude","aggressive");
            return 1;
    }else
    return 0;
}
int unequip()
{
    if (::unequip()){
            environment()->set("attitude","heroism");
            return 1;
    }else
    return 0;
}
*/
int query_autoload() { return 1; }