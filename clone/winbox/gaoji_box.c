// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIM"�߼�����"NOR,({"boxno3"}));
        set_weight(5000);
       
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "����ϵͳ������"+this_object()->query("name")+",ʹ��(openbox boxno3)�򿪿���!\n");
            set("unit","��");
            set("icon","06002");
            set("win_box",1);
        }
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno3",1);
}
//�򿪱���ĺ���
int do_openbox()
{
   int i;
   int num=1;
   object ob;
 /*
   * �ƽ�,����ҩ,��ҩ,�˺���,�ǹ�,������װ,�ƴ�,����,�ؼ����,ǧ����
  */
   string *box=
({
"/clone/money/gold","/clone/misc/fashao","/clone/misc/gaoyao","/clone/misc/shanghan","/clone/gift/tang","/clone/food/jiudai","/clone/food/jitui","/clone/book/advance-blade","/clone/suit/huashan/ling_boots","/clone/suit/huashan/ling_cloth",
"/clone/suit/huashan/ling_pants","/clone/suit/huashan/ling_sword",
"/clone/book/advance-club","/clone/book/advance-dagger","/clone/book/advance-dodge","/clone/book/advance-force","/clone/book/advance-parry","/clone/book/advance-unarmed","/clone/book/advance-sword","/clone/book/advance-staff","/clone/book/advance-throwing",
"/clone/book/advance-whip",
});
  
    object me = this_player();
        if (me->is_busy())
              { write("����һ������δ��ɣ�\n"); return 1;}
        if( me->is_fighting() )
              { write("ս���п����䣿����ѽ��\n"); return 1;}
       

    message_vision(HIM"$N�������["+this_object()->query("name")+"]�ĸ���,���仪Ϊһ����ɫ�⻪��\n"NOR,me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
   
    if(ob->query("base_value"))
    {
       num=random(5)+1;
       ob->set_amount(num);
    }
    
  tell_object(me,""HIM"**************************************************************\n");
  tell_object(me,""HIR"<��ϲ>: "NOR" ���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIM"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}