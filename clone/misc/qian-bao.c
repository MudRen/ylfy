// 宝箱

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             
void create()
{
	set_name(HIR"钱包"NOR, ({"qianbao"}));        
	set_weight(1000);
	set_weight(10);
    set("icon","00012");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个钱包，也不知道是哪个笨蛋丢的，到底要不要打开呢？(open qianbao)。\n");
		set("unit", "个");
		set("value", 10000);
	}
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object obj1, obj2, obj3, obj4;
        object me = this_player();
        if (arg == "qianbao")
        {
       message_vision("$N充满憧憬地打开了钱包！\n", me);
   
                if (random(10) == 0)
                {
                        obj1 = new("/clone/misc/jineng-book");
                        obj1->move(me);
						tell_object(me,"发现了一本技能书。\n"NOR);
                }
                if (random(3) == 1)
                {
                        obj2 = new("/clone/money/thousand-gold");
                        obj2->move(me);
						tell_object(me,"发现了一张金票。\n"NOR);
                }
                if (random(5) == 2)
                {
                        obj3 = new("/clone/drug/shenbao");
                        obj3->move(me);
						tell_object(me,"发现了一瓶肾宝。\n"NOR);
                }
               obj4 = new("/clone/drug/jiuhua");
			   obj4->move(me);
			   tell_object(me,"发现了一颗九花玉露丸。\n"NOR);
                destruct(this_object());
        }
        return 1;
}
int query_autoload(){ return 1; }