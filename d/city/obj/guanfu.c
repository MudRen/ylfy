
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�ٷ�", ({ "guanfu","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
		set("no_sell",1);
		set("value",200);
		set("long","һ����͢���ٴ��ŵĹٷ��������ý�˿������һЩ���ơ�\n");
                set("armor_prop/armor", 20);
        }
        setup();
}
int query_autoload() { return 1; }