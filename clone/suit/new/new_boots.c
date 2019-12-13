// news_cloth.c

#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(HIG "新丁快靴" NOR, ({"new boots"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一件suimeng特别为新人订做的靴子，穿戴可提升一些精气。\n");
                set("material", "boots");    //类型
                set("armor_prop/armor", 500);  //防御
                set("armor_prop/warm", 3);   //保暖
                set("value", 1000);   //价值
				set("no_sell",1);
       //---------------------------------------------------------------
              //套装参数
                set("suit",HIG"新丁套装"NOR);  //套装名称
                set("suit_lvl",1);             //套装等级
                set("suit_count",3);           //套装部件数量
              //套装各部件
                set("suit_mod/cloth","新丁长衫");
                set("suit_mod/boots","新丁快靴");
                set("suit_mod/pants","新丁长裤");
             
              //套装全部附加天赋效果  
                set("suit_eff/strength",3000);      //两件
                set("suit_eff/constitution",3000);      // 五件 
                set("suit_eff/intelligence",3000);      //三件  
				set("suit_eff/dexerity",3000); 
                set("suit_eff/damage",10000);      //    一套
                //set("suit_eff/composure",1);      //两件
                //set("suit_eff/personality",1);      // 五件 
                //set("suit_eff/constitution",1);      //三件  
                //set("suit_eff/karma",1);      //    一套
                //套装全部附加技能效果     
              // set("suit_eff_skill/literate",1000);                 			   
              // set("suit_eff_skill/unarmed",1000);
			  // set("suit_eff_skill/parry",1000);
			  // set("suit_eff_skill/dodge",1000);
       //---------------------------------------------------------------
        }
        setup();
}

/*int wear()
{
	int i;
	i = this_object()->query("armor_prop/level");
	if (::wear())
	{
		this_player()->add("max_qi", 30000);
		this_player()->add("max_jing", 10000);
		return 1;
	}
	else
		return 0;
}
int unequip()
{
	int i;
	i = this_object()->query("armor_prop/level");
	if (::unequip())
	{
		this_player()->add("max_qi", -30000);
		this_player()->add("max_jing", -10000);
        if( this_player()->query("eff_qi") > this_player()->query("max_qi") )
		this_player()->set("eff_qi", this_player()->query("max_qi") );
	if( this_player()->query("qi") > this_player()->query("max_qi") )
		this_player()->set("qi", this_player()->query("max_qi") );

	if( this_player()->query("eff_jing") > this_player()->query("max_jing") )
		this_player()->set("eff_jing", this_player()->query("max_jing") );
	if( this_player()->query("jing") > this_player()->query("max_jing") )
		this_player()->set("jing", this_player()->query("max_jing") );
		return 1;
	}
	else
		return 0;
}
*/
int query_autoload()
{
        return 1;
}
