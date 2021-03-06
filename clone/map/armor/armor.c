// 动态物品：铠甲

#include <armor.h>
#include <ansi.h>

inherit ARMOR;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing)) );
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL"));

	name = get_item_name(pj, lvl);
	id = get_item_id(name, "kai");
	
	armor = random(lvl * 100);
	
	if ( !armor || armor < 100 )
		armor = random(100);

	set_name(name + "铠"NOR, ({ id, "kai", "armor" }) );
	set_weight(300 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 2000000 + (random(pj + lvl) * 1000000));
	set("armor_prop/level", lvl);
	get_item_shuxing("armor", pj, lvl, 1);
	set("armor_prop/armor", armor);
	set("material", "steel");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "件");
	set("icon", "10069");
	set("long", "这是一件沉重结实的钢铁铠甲，有着坚固的防御能力，据说乃是神界工匠所制作的。\n");
	setup(1);
}