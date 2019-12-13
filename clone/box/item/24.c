// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("玄铁剑", ({ "xuantie sword", "sword", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的玄铁剑，一般的剑客都配带此剑。\n");
		set("value", 200000);
		set("material", "steel");
		set("icon", "10023");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(300);
	setup();
}
