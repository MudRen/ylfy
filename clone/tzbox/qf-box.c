// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"�ط籦��"NOR,({"boxno1"}));
        set_weight(500);
        
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "����ϵͳ������"+this_object()->query("name")+",ʹ��(openbox boxno1)�򿪿���!\n");
        set("unit","��");
        set("value", 1000000);
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno1",1);
}
//�򿪱���ĺ���
int do_openbox()
{
   int i;
   int num=1;
   object ob;
   
   string *box=
({
"/clone/suit/qinfeng/qf-armor","/clone/suit/qinfeng/qf-boots","/clone/suit/qinfeng/qf-cloth","/clone/suit/qinfeng/qf-hand","/clone/suit/qinfeng/qf-head","/clone/suit/qinfeng/qf-neck",
"/clone/suit/qinfeng/qf-pants","/clone/suit/qinfeng/qf-ring","/clone/suit/qinfeng/qf-shield","/clone/suit/qinfeng/qf-surcoat","/clone/suit/qinfeng/qf-waist","/clone/suit/qinfeng/qf-wrists"
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