// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"˷ѩ����"NOR,({"boxno2"}));
        set_weight(500);
        
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "����ϵͳ������"+this_object()->query("name")+",ʹ��(openbox boxno2)�򿪿���!\n");
        set("unit","��");
        set("value", 1000000);
            
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno2",1);
}
//�򿪱���ĺ���
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
              { write("����һ������δ��ɣ�\n"); return 1;}
        if( me->is_fighting() )
              { write("ս���п����䣿����ѽ��\n"); return 1;}
       
    message_vision(HIG"$N�������["+this_object()->query("name")+"]�ĸ���,���仪Ϊһ���ɫ�⻪��\n"NOR,me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 

   tell_object(me,""HIY"**************************************************************\n");
  tell_object(me,""HIR"<��ϲ>: "NOR" ���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIY+"<< "+ob->query("name")+HIY+" >>"+NOR+"\n");
 tell_object(me,""HIY"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}