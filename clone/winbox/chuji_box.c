// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"��������"NOR,({"boxno1"}));
        set_weight(5000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
            set("long",
                "����ϵͳ������"+this_object()->query("name")+",ʹ��(openbox boxno1)�򿪿���!\n");
            set("unit","��");
            set("icon","06000");
           set("win_box",1);
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
/*
    ͭǮ,����ҩ,��ҩ,�˺���,�ǹ�,������װ,�ƴ�,����,�����ڹ�,����ȭ��,���־�,���߰���
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
              { write("����һ������δ��ɣ�\n"); return 1;}
        if( me->is_fighting() )
              { write("ս���п����䣿����ѽ��\n"); return 1;}
       
    message_vision(HIG"$N�������["+this_object()->query("name")+"]�ĸ���,���仪Ϊһ����ɫ�⻪��\n"NOR,me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
      if(ob->query("base_value"))
    {
       num=random(30)+1;
       ob->set_amount(num);
    }
  tell_object(me,""HIG"**************************************************************\n");
  tell_object(me,""HIR"<��ϲ>: "NOR" ���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIG+"<< "+ob->query("name")+HIG" >>"+NOR+"\n");
 tell_object(me,""HIG"**************************************************************\n");
    ob->move(me); 
    destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}