// corpse_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIM"许愿卡"NOR,({"lack card","card"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "珍贵的<"+this_object()->query("name")+">,使用(xuyuan lack card)许愿看看!\n");
            set("unit","个");
            set("icon","06007");
            
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_xuyuan","xuyuan lack card",1);
}
//打开宝箱的函数
int do_xuyuan()
{
   int i;
   int num=1;

   object ob;

  
    object me = this_player();
        if (me->is_busy())
              { write("你上一个动作未完成！\n"); return 1;}
        if( me->is_fighting() )
              { write("战斗中使用许愿卡？挨宰呀？\n"); return 1;}
       
    message_vision(HIG"$N双手抓着["+this_object()->query("name")+"],轻声念出了卡中浮现的文字！\n"NOR,me);
    i=random(100);
    if(i > 0 && i <= 50)
    {
        ob = new("/clone/box/chuji_box"); 
    }
    else if(i > 50 && i <= 80)
    {
        ob = new("/clone/box/zhongji_box"); 
    }
    else if(i > 80 && i <= 90)
    {
        ob = new("/clone/box/gaoji_box"); 
    }
    else if(i > 90 && i <= 95)
    {
        ob = new("/clone/box/chaoji_box"); 
    }
    else if(i == 99)
    {
        ob = new("/clone/box/vip_box"); 
    }
    else
    {
         tell_object(me,""HIR"<....>: "NOR" *许愿卡*化为..."WHT"一堆粉末"NOR"\n");
         return 1;
    }
  tell_object(me,""HIM"**************************************************************\n");
  tell_object(me,""HIR"<恭喜>: "NOR" ["+this_object()->query("name")+"]化为..."+chinese_number(num)+ob->query("unit")+HIG+"<< "+ob->query("name")+HIG" >>"+NOR+"\n");
 tell_object(me,""HIM"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}