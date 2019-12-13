// ��̬��Ʒ��ѥ��

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing)) );
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL"));

	name = get_item_name(pj, lvl);
	id = get_item_id(name, "xue");
	
	armor = random(lvl * 100);
	
	if ( !armor || armor < 100 )
		armor = random(100);

	set_name(name + "ѥ"NOR, ({ id,"xue", "boots"} ) );
	set("long", "����һ˫�����ǳ���ϸ��ѥ�ӣ���˵�˳�����繤��֮�֡�\n");
	set_weight(300 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 2000000 + (random(pj + lvl) * 1000000));
	set("armor_prop/level", lvl);
	get_item_shuxing("armor", pj, lvl, 1);	
	set("armor_prop/armor", armor);
	set("material", "leather");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "��");
	set("icon", "10070");
	setup(1);
	}
