// caoxie.c ��Ь
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("��Ь", ({ "sandals", "cao xie", "xie" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "˫");
		set("icon", "10003");
		set("long", "����һ˫�ݱ�Ĳ�Ь�����Ա����㲿��\n");
		set("value", 100);
		set("armor_prop/dodge", 2);
	}
	setup();
}
int query_autoload() { return 1; }	
