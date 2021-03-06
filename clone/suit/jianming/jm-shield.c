// 剑茗套装：盾牌

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit SHIELD;
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
		set("armor_prop/"+item[i], ITEM_LEVEL * 100);   // 设置常规属性
	}
	set_name(YEL"剑茗盾牌"NOR, ({ "jianming dun","dun", "shield" }) );
	set("long", "这是一面防护性极好的钢铁护盾，有着坚固的防御能力，属于传说中的剑茗套装中的一件。\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "steel");
	set("xyzx_item/pinji", 2);
	set("owner_id",1);
	set("max_level", 30);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "面");
	set("icon", "10079");
 //---------------------------------------------------------------
              //套装参数
    set("suit",YEL"剑茗套装"NOR);  //套装名称
    set("suit_lvl", 3);             //套装等级
    set("suit_count",10);           //套装部件数量
              //套装各部件
    set("suit_mod/armor","剑茗铠甲");
    set("suit_mod/boots","剑茗长靴");
    set("suit_mod/pants","剑茗长裤");
    set("suit_mod/hand","剑茗护手");
    set("suit_mod/head","剑茗头盔");
    set("suit_mod/neck","剑茗项链");
    set("suit_mod/cloth","剑茗长衫");
    set("suit_mod/ring","剑茗戒指");
    set("suit_mod/shield","剑茗盾牌");
    set("suit_mod/surcoat","剑茗披风");
    set("suit_mod/waist","剑茗腰带");
	set("suit_mod/wrists","剑茗护腕");
		//套装全部附加天赋效果  
    set("suit_eff/dexerity", 50000);      
    set("suit_eff/intelligence", 50000);      
    set("suit_eff/constitution", 50000);      
    set("suit_eff/strength", 50000);      
    //套装全部附加技能效果     
    set("suit_eff_skill/taiji-shengong", 1000);   
                
 //---------------------------------------------------------------
	setup(1);
}

