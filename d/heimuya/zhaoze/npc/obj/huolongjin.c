#include <weapon.h>
inherit ITEM;

void create()
{
        set_name("������", ({ "huolong jin", "jin" }) );
        set_weight(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ȥ�ƺ�ʮ�ּ��͡�\n");
                set("value", 3);
                set("material", "leather");
        }
}

int query_autoload() { return 1; }