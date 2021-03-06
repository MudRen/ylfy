// 秦风套装：衣服

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit CLOTH;
inherit F_ITEM_MAKE;
//#include <item_sx.h>

void create()
{
	string *item;
	int i, max;

	item = keys(armor_shuxing);
	max = sizeof(item);
	for ( i=0; i < max; i++ )
	{
		set("armor_prop/"+item[i], ITEM_LEVEL * 100);  // 设置常规属性
	}
	set_name(HIR"秦风长衫"NOR, ({ "qinfeng yi","yi", "cloth" }) );
	set("long", "这是一件做工非常精细的服装，属于传说中的秦风套装中的一件。\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "cloth");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("xyzx_item/pinji", 1);
	set("unit", "件");
	set("icon", "10071");
 //---------------------------------------------------------------
              //套装参数
    set("suit",HIR"秦风套装"NOR);  //套装名称
    set("suit_lvl", 1);             //套装等级
    set("suit_count",10);           //套装部件数量
              //套装各部件
    set("suit_mod/armor","秦风铠甲");
    set("suit_mod/boots","秦风长靴");
    set("suit_mod/pants","秦风长裤");
    set("suit_mod/hand","秦风护手");
    set("suit_mod/head","秦风头盔");
    set("suit_mod/neck","秦风项链");
    set("suit_mod/cloth","秦风长衫");
    set("suit_mod/ring","秦风戒指");
    set("suit_mod/shield","秦风盾牌");
    set("suit_mod/surcoat","秦风披风");
    set("suit_mod/waist","秦风腰带");
	set("suit_mod/wrists","秦风护腕");
//套装全部附加天赋效果  
    set("suit_eff/dexerity", 60000); 
    set("suit_eff/intelligence", 60000);  
    set("suit_eff/constitution", 60000);  
    set("suit_eff/strength", 60000); 
	set("suit_eff/armor", 60000);
    set("suit_eff/damage", 10000); 
    //套装全部附加技能效果     
    /*set("suit_eff_skill/huagong-dafa", 100);  
	set("suit_eff_skill/beiming-shengong", 100);
	set("suit_eff_skill/xixing-dafa", 100);*/              
 //---------------------------------------------------------------
	setup(1);
}
