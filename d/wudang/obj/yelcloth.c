// yelcloth.c ��ɫ����
// By wyz
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name( YEL "��ɫ����" NOR, ({"pao"}) );
    set_weight(4500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "���Ǽ���ɫ���ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 3);
    }
    setup();
}

int query_autoload() { return 1; }