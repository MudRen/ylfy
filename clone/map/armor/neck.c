// 动态物品：项链

#include <armor.h>
#include <ansi.h>

inherit NECK;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing) ));
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL"));

	name = get_item_name(pj, lvl);
	id = get_item_id(name, "xianglian");
	
	armor = random(lvl * 100);
	
	if ( !armor || armor < 100 )
		armor = random(100);

	set_name(name + "项链"NOR, ({ id, "xianglian", "neck" }) );
	set_weight(300 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 2000000 + (random(pj + lvl) * 1000000));
	set("armor_prop/level", lvl);
	get_item_shuxing("armor", pj, lvl, 1);
	set("armor_prop/armor", armor);
	set("material", "gem");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "条");
	set("icon", "10077");
	set("long", "这是一条做工精美的宝石项链，传说乃出自神界工匠之手。\n");
	setup(1);
}