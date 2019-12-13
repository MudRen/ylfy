// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"初级宝箱"NOR,({"boxno1"}));
        set_weight(5000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "这是系统奖励的"+this_object()->query("name")+",使用(openbox boxno1)打开看看!\n");
            set("unit","个");
            set("icon","06000");
           set("win_box",1);
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno1",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;

   object ob;
/*
    铜钱,退烧药,膏药,伤寒愁,糖果,新手套装,酒袋,鸡腿,基本内功,基本拳脚,三字经,乱七八糟
*/
   string *box=
({
"/clone/money/coin","/clone/misc/fashao","/clone/misc/gaoyao","/clone/misc/shanghan","/clone/gift/tang","/clone/suit/new/new_boots","/clone/suit/new/new_pants","/clone/suit/new/new_sword","/clone/suit/new/new_cloth","/clone/food/jiudai","/clone/food/jitui",
"/clone/book/basic-force","/clone/book/basic-unarmed",
"/clone/food/fish","/clone/food/baozi","/clone/food/zongzi","/clone/food/xia",
"/clone/food/tofu","/clone/food/peanut","/clone/cloth/dao-xie",
"/clone/cloth/tiejia","/clone/cloth/cuttonp","/clone/gift/icecream-vanilla",
"/clone/gift/icecream-chocolate","/clone/misc/shoeshine","/clone/misc/xiaoshu",
});
  
    object me = this_player();
        if (me->is_busy())
              { write("你上一个动作未完成！\n"); return 1;}
        if( me->is_fighting() )
              { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
    message_vision(HIG"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱华为一阵绿色光华！\n"NOR,me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
      if(ob->query("base_value"))
    {
       num=random(30)+1;
       ob->set_amount(num);
    }
  tell_object(me,""HIG"**************************************************************\n");
  tell_object(me,""HIR"<恭喜>: "NOR" 你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIG+"<< "+ob->query("name")+HIG" >>"+NOR+"\n");
 tell_object(me,""HIG"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}