#include <weapon.h>
inherit THROWING;
void create()
{
        set_name(HIW "����" NOR , ({ "qi zi","qi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "����һ��Χ���ӡ�\n");
                set("unit", "��");
                set("base_unit", "ö");
                set("base_weight", 1);
                set("base_value", 10);
        }
        set_amount(100);
        init_throwing(2,2);
        setup();
}
int query_autoload() { return 1; }