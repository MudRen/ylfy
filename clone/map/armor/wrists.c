// 动态物品：护腕

#include <armor.h>
#include <ansi.h>

inherit WRISTS;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing)) )+1;
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL"));

	name = get_item_name(pj, lvl);
	id = get_item_id(name, "huwan");
	
	armor = random(lvl * 100);
	
	if ( !armor || armor < 100 )
		armor = random(100);

	set_name(name + "护腕"NOR, ({ id, "huwan", "wrists" }) );
	set_weight(300 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 2000000 + (random(pj + lvl) * 1000000));
	set("armor_prop/level", lvl);
	get_item_shuxing("armor", pj, lvl, 1);
	set("armor_prop/armor", armor);
	set("material", "steel");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "副");
	set("icon", "10082");
	set("long", "这是一副做工异常细致，有着良好防护性的护腕，传说乃出自神界工匠之手。\n");
	setup(1);
}