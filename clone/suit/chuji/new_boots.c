// news_cloth.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

string do_wear();

void create()
{
        set_name(HIG "①新丁快靴" NOR, ({"new boots"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一件新丁快靴，是suimeng特别为新人订做的。\n");
                set("material", "boots");    //类型
                set("armor_prop/armor", 500);  //防御
                set("armor_prop/warm", 3);   //保暖
                set("value", 1000);   //价值
				set("no_sell",1);
                set("wear_msg", (: do_wear :));  //装备信息
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
                set("suit_eff/strength",5000);      //两件
                set("suit_eff/constitution",5000);      // 五件 
                set("suit_eff/intelligence",5000);      //三件  
				set("suit_eff/dexerity",5000); 
                set("suit_eff/armor",5000);      //    一套
                //set("suit_eff/composure",1);      //两件
                //set("suit_eff/personality",1);      // 五件 
                //set("suit_eff/constitution",1);      //三件  
                //set("suit_eff/karma",1);      //    一套
                //套装全部附加技能效果     
               set("suit_eff_skill/literate",1000);                 			   
               set("suit_eff_skill/unarmed",1000);
			   set("suit_eff_skill/parry",1000);
			   set("suit_eff_skill/dodge",1000);
       //---------------------------------------------------------------
        }
        setup();
}

string do_wear()
{
        object me;
        string msg;
        int per;

        me = this_player();
        per = me->query("per");
        if (me->query("gender") == "女性")
        {
                if (per >= 30)
                        msg = HIC "$N" HIC "轻轻将一件$n" HIC "穿在脚上，神态曼妙之极。\n";
                else if (per >= 25)
                        msg = HIG "$N" HIG "把$n" HIG "展开，穿在脚上。\n";
                else if (per >= 20)
                        msg = YEL "$N" YEL "把$n" YEL "穿在脚上，缩了缩脖子。\n";
                else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在脚上。\n";
        } else
        {
                if (per >= 30)
                        msg = HIC "$N" HIC "随手一挥，将$n" HIC "穿在脚上，姿势潇洒之极。\n";
                else if (per >= 25)
                        msg = HIG "$N" HIG "把$n" HIG "展开，穿在脚上。\n";
                else if (per >= 20)
                        msg = YEL "$N" YEL "把$n" YEL "穿在脚上，扯了扯衣角，缩了缩脖子。\n";
                else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在脚上，甚是猥琐。\n";
        }
        return msg;
}

int query_autoload()
{
        return 1;
}
