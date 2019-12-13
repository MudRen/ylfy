// ��̬��Ʒ����

#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_ITEM_MAKE;

void create()
{
	string name, id;
	int pj, lvl, damage, item_type;

	pj = random( (int) (sizeof(weapon_shuxing)) );
	lvl = random(get_system_config(DATA_CONFIG_DIR "weapon.h", "ITEM_WEAPON_MAX_LEVEL"));

	name = get_item_name(pj, lvl);
	id = get_item_id(name, "staff");
	
	damage = lvl * 100;
	damage /= 2;
	damage = damage + random(damage);
	
	if ( !damage || damage < 100 )
		damage = random(100);

	item_type = 1 + random(2);//��˫�����
	//item_type = 2; //ָ��Ϊ����

	set_name(name + "��"NOR, ({ id, "staff", "zhang" }) );
	set_weight(3000 + (random(pj) * 100) + (random(lvl) * 100));
	set("value", 3000000 + (random(pj + lvl) * 1000000));
	set("weapon_prop/level", lvl);
	get_item_shuxing("weapon", pj, lvl, 1);
	
	set("unit", "��");
	set("icon", "10041");
	set("material", "steel");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("long", "����һ���ǿ�Ѱ���ĳ��ȣ���˵��������磬�Ƿ���ʵ���޴�׷���ˡ�\n");

	init_staff(damage, item_type, 1);

	setup();
}