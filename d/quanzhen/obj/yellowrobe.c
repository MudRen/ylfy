// greyrobe.txt; �ӻ�ɫ����
// By kyd

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ӻ�ɫ����", ({"pao", "cloth", "dao pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ������ͨͨ���ӻ�ɫ���ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}