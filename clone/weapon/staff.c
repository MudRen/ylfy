// weapon: tiegun.c
// Jay 3/18/96
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("����", ({ "tie staff", "staff" }) );
        set_weight(1500);
                set("flag",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ȣ��ƺ���������\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_staff(40,2);
        setup();
}
int query_autoload() { return 1; }