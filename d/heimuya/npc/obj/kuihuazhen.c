	// kuihuazhen.c
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("������", ({ "kuihuazhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "��������һ��ר�Ŵ��Ƶİ��������μ�����ɱ����ǿ.\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(200);
        init_throwing(20,2);
        setup();
}
int query_autoload() { return 1; }