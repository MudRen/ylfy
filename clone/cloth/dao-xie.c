// dao-xie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIY "��Ь" NOR, ({ "ma xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�಼��Ь��\n");
        set("value", 10000);
		set("material", "boots");
		set("armor_prop/dodge", 5);
	}
	setup();
}
int query_autoload() { return 1; }