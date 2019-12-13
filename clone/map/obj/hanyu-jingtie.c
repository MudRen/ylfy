// 最大属性增幅值
#define ADD_MAX_SX_NUM 1000
// 可提升的最高等级
#define MAX_LEVLUP_NUM 30

inherit ITEM;
inherit F_SAVE;
#include <item_sx.h>

void create()
{	      
	set_name( HIW"寒玉精铁"NOR, ({"hanyu jingtie"}) );
    set_weight(5);
	set("long", "一块比较常见的材料，可以使用内力将他熔炼(ronglian)在兵甲上提升属性。\n"NOR);	
	set("unit", "块");
	set("value", 1);
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);

	setup();
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_ronglian", "ronglian");
}

int do_ronglian(string arg)
{
	object me, ob, obj;
	string str, item, *item_sx, *item_jc;
	int i, v, sx_num;

	me = this_player();
	ob = this_object();
	v = 0;

	if ( environment(ob) != me )
		return 0;
	
	if ( !arg )
		return notify_fail("你要把寒玉精铁熔炼(ronglian)到什么上？\n");
	
	if ( sscanf(arg, "%s to %s", str, item) != 2 )
		return notify_fail("指令格式：ronglian 寒玉精铁英文名 to 装备英文名\n");
	
	//if ( !objectp(ob = present(str, me)) || !function_exists("do_tie", ob) )
	//	return notify_fail("指令格式：tie 符纸英文名 to 装备英文名\n");
	
	if ( !objectp(obj = present(item, me)) && !objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	
	if ( !obj->query("armor_prop/armor") && !obj->query("weapon_prop/damage") )
		return notify_fail("你只能用寒玉精铁提升武器或防具的等级。\n");
	
	if ( obj->query("equipped") )
      return notify_fail("你必须解除对这件物品的装备才能用寒玉精铁进行。\n");
   
    if ( obj->query("weapon_prop/damage") )
		v = obj->query("weapon_prop/level");
	
	else if ( obj->query("armor_prop/armor") )
		v = obj->query("armor_prop/level");
	
    if ( v >= 30 )
      return notify_fail("这件装备已经满级了，还想提升什么。\n");
  
	if ( obj->is_character() )
      return notify_fail("你要把寒玉精铁熔炼(ronglian)到什么上？\n");

      if ( obj->query("no_tie"))                                      
        return notify_fail("这样装备不能提升等级。\n");
      
	// 失败率设定
	if ( random(MAX_LEVLUP_NUM + 1) < v )	
	{
		message_vision(HIM"$N试图用内力把寒玉精铁熔炼到" + obj->query("name") + HIM"上提升等级，寒玉精铁却在你的内力催动下直接变成了蒸汽。\n"NOR, me);
		tell_object(me, HIY + obj->query("name") + HIY"等级提升失败。\n"NOR);
		destruct(ob);
		return 1;
	}	
	
	if ( obj->query("weapon_prop/damage") )
	{
		message_vision(HIM"$N把寒玉精铁熔炼到" + obj->query("name") + HIM"上，" + obj->query("name") + HIM"的等级提升至"HIW + chinese_number(obj->query("weapon_prop/level") + 1) + "级" + HIM"。\n"NOR, me);
		item_sx = keys(weapon_shuxing);
		item_jc = values(weapon_shuxing);
		v = sizeof(item_sx);
		for (i = 0; i < v; i++)
		{
			if ( obj->query("weapon_prop/" + item_sx[i]) )
			{
				sx_num = obj->query("weapon_prop/" + item_sx[i]) * (obj->query("weapon_prop/level") + 1) / 100;
				if ( sx_num < 1 )
					sx_num = 1;
				else if ( sx_num > ADD_MAX_SX_NUM )
					sx_num = ADD_MAX_SX_NUM;
				obj->add("weapon_prop/" + item_sx[i], sx_num);
				message_vision(HIG + obj->query("name") + HIG"的" + item_jc[i] + "增幅效果提升了"HIW + chinese_number(sx_num) + "点。\n"NOR, me, ob);
			}
		}
		obj->add("weapon_prop/level", 1);
		// 价值提升
		obj->add("value", obj->query("value") / 100 * obj->query("weapon_prop/level"));
	}
	else if ( obj->query("armor_prop/armor") )
	{
		message_vision(HIM"$N把寒玉精铁粘贴到" + obj->query("name") + HIM"上，" + obj->query("name") + HIM"的等级提升至"HIW + chinese_number(obj->query("armor_prop/level") + 1) + "级" + HIM"。\n"NOR, me);
		item_sx = keys(armor_shuxing);
		item_jc = values(armor_shuxing);
		v = sizeof(item_sx);
		for (i = 0; i < v; i++)
		{
			if ( obj->query("armor_prop/" + item_sx[i]) )
			{
				sx_num = obj->query("armor_prop/" + item_sx[i]) * (obj->query("armor_prop/level") + 1) / 100;
				if ( sx_num < 1 )
					sx_num = 1;
				else if ( sx_num > ADD_MAX_SX_NUM )
					sx_num = ADD_MAX_SX_NUM;
				obj->add("armor_prop/" + item_sx[i], sx_num);
				message_vision(HIG + obj->query("name") + HIG"的" + item_jc[i] + "增幅效果提升了"HIW + chinese_number(sx_num) + "点。\n"NOR, me, ob);
			}
		}
		obj->add("armor_prop/level", 1);
		// 价值提升
		obj->add("value", obj->query("value") / 100 * obj->query("armor_prop/level"));
	}

	obj->set("xyzx_save_item", 1);
	obj->set("owner_id", 1);
	destruct(ob);
	return 1;
}