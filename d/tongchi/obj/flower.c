#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
       set_name(MAG"���ֻ�"NOR, ({"fenglin flower", "flower"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000); 
      set("long", "����ǽ�����˵���ܹ��������˵�����֮�������ֻ���\n");
        }
        setup();
}

int do_eat(string arg)
{
       
           object me = this_player();
        if (!id(arg))
          return notify_fail("��Ҫ��ʲô��\n");
     {
                if ( me->query("kar") < 30)

         {
    message_vision(RED"$N�ſ�����,һ�ڰ�"+this_object()->name()+RED+"����!\n" NOR,this_player());
                  message_vision(MAG
   "$N��Ȼ����һ�������ɵ���֮��ֱ��������...........\n" NOR, this_player());
         this_player()->add("kar", 1);
         this_object()->move(VOID_OB);
            this_player()->unconcious();
         destruct(this_object());
 return 1;
         }
     message_vision(RED"$N�ſ�����,һ�ڰ�"+this_object()->name()+RED+"����!\n" NOR,this_player());
          message_vision(MAG"$N��Ȼ����ͷ�ؽ���,������$N����̫��ķ��ֻ����˷�Ч��...........\n" NOR, this_player());
         this_player()->set("kar", 30);
    this_player()->unconcious();
       this_object()->move(VOID_OB);
    destruct(this_object());
     return 1;
}

}
