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
       set_name(MAG"风林花"NOR, ({"fenglin flower", "flower"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("value", 5000); 
      set("long", "这就是江湖传说中能够带来幸运的幸运之花，风林花。\n");
        }
        setup();
}

int do_eat(string arg)
{
       
           object me = this_player();
        if (!id(arg))
          return notify_fail("你要吃什么？\n");
     {
                if ( me->query("kar") < 30)

         {
    message_vision(RED"$N张开大嘴,一口把"+this_object()->name()+RED+"吞了!\n" NOR,this_player());
                  message_vision(MAG
   "$N忽然觉得一股热流由丹田之处直冲向脑子...........\n" NOR, this_player());
         this_player()->add("kar", 1);
         this_object()->move(VOID_OB);
            this_player()->unconcious();
         destruct(this_object());
 return 1;
         }
     message_vision(RED"$N张开大嘴,一口把"+this_object()->name()+RED+"吞了!\n" NOR,this_player());
          message_vision(MAG"$N忽然觉得头重脚轻,可能是$N吃了太多的风林花起了反效果...........\n" NOR, this_player());
         this_player()->set("kar", 30);
    this_player()->unconcious();
       this_object()->move(VOID_OB);
    destruct(this_object());
     return 1;
}

}
