#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("木刀", ({ "blade", "blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		  set("icon", "10009");
		set("value", 500);
		set("material", "iron");
		set("long", "这是一柄半新不旧的有张无忌名字的木刀。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(5);
	setup();
}int query_autoload() { return 1; }