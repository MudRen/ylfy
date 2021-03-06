// 动态物品：靴子

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing) / 2) );
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL") + 1);

	name = get_item_name(pj, lvl);
	if ( random(10) > 5 )
	{
		id = get_item_id(name, "xue");
		set_name(name + "靴"NOR, ({ id, "xue", "boots" }) );
		set("material", "leather");
		set("long", "这是一双做工非常精细的靴子，传说乃出自神界中美丽的精灵们之手。\n");
		set("icon", "10070");
	}
	else
	{
		id = get_item_id(name, "xie");
		set_name(name + ""NOR, ({ id, "xie", "boots" }) );
		set("material", "cloth");
		set("female_only", 1);
		set("long", "这是一双做工非常精细的鞋子，传说乃出自神界中美丽的精灵们之手。\n");
		set("icon", "10076");
	}
	
	armor = random(lvl * 100);
	
	if ( !armor || armor < 100 )
		armor = random(100);

	set_weight(300 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 3000000 + (random(pj + lvl) * 1000000));
	set("armor_prop/level", lvl);
	get_item_shuxing("armor", pj, lvl, 1);
	set("armor_prop/armor", armor);
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "双");	
	setup(1);
}