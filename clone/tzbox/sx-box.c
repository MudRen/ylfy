// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"朔雪宝箱"NOR,({"boxno2"}));
        set_weight(500);
        
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "这是系统奖励的"+this_object()->query("name")+",使用(openbox boxno2)打开看看!\n");
        set("unit","个");
        set("value", 1000000);
            
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno2",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   object ob;
   
   string *box=
({
"/clone/suit/shuoxue/sx-armor","/clone/suit/shuoxue/sx-boots","/clone/suit/shuoxue/sx-cloth","/clone/suit/shuoxue/sx-hand","/clone/suit/shuoxue/sx-head","/clone/suit/shuoxue/sx-neck",
"/clone/suit/shuoxue/sx-pants","/clone/suit/shuoxue/sx-ring","/clone/suit/shuoxue/sx-shield","/clone/suit/shuoxue/sx-surcoat","/clone/suit/shuoxue/sx-waist","/clone/suit/shuoxue/sx-wrists"
});
  
    object me = this_player();
        if (me->is_busy())
              { write("你上一个动作未完成！\n"); return 1;}
        if( me->is_fighting() )
              { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
    message_vision(HIG"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱华为一阵金色光华！\n"NOR,me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 

   tell_object(me,""HIY"**************************************************************\n");
  tell_object(me,""HIR"<恭喜>: "NOR" 你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIY+"<< "+ob->query("name")+HIY+" >>"+NOR+"\n");
 tell_object(me,""HIY"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}