// ��̬��Ʒ��ñ��

#include <armor.h>
#include <ansi.h>

inherit HEAD;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, armor;

	pj = random( (int) (sizeof(armor_shuxing) / 2) );
	lvl = random(get_system_config(DATA_CONFIG_DIR "armor/cloth.h", "ITEM_CLOTH_MAX_LEVEL") + 1);

	name = get_item_name(pj, lvl);

	if ( random(10) > 5)
	{
		id = get_item_id(name, "toukui");
		set_name(name + "ͷ��"NOR, ({ id, "toukui", "head" }) );
		set("material", "steel");
		set("icon", "10073");
		set("long", "����һ���ǳ���Ӳ��ʵ�ĸ���ͷ������˵�˳�����簫�˹���֮�֡�\n");
	}
	else
	{
		id = get_item_id(name, "mao");
		set_name(name + "ñ"NOR, ({ id, "mao", "head" }) );
		set("female_only", 1);
		set("material", "leather");
		set("icon", "10074");
		set("long", "����һ�������ǳ���ϸ�Ļ�ñ����˵�˳�������������ľ�����֮�֡�\n");
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
	set("unit", "��");
	setup(1);
}