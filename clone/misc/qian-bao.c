// ����

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             
void create()
{
	set_name(HIR"Ǯ��"NOR, ({"qianbao"}));        
	set_weight(1000);
	set_weight(10);
    set("icon","00012");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��Ǯ����Ҳ��֪�����ĸ��������ģ�����Ҫ��Ҫ���أ�(open qianbao)��\n");
		set("unit", "��");
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
       message_vision("$N�����㽵ش���Ǯ����\n", me);
   
                if (random(10) == 0)
                {
                        obj1 = new("/clone/misc/jineng-book");
                        obj1->move(me);
						tell_object(me,"������һ�������顣\n"NOR);
                }
                if (random(3) == 1)
                {
                        obj2 = new("/clone/money/thousand-gold");
                        obj2->move(me);
						tell_object(me,"������һ�Ž�Ʊ��\n"NOR);
                }
                if (random(5) == 2)
                {
                        obj3 = new("/clone/drug/shenbao");
                        obj3->move(me);
						tell_object(me,"������һƿ������\n"NOR);
                }
               obj4 = new("/clone/drug/jiuhua");
			   obj4->move(me);
			   tell_object(me,"������һ�žŻ���¶�衣\n"NOR);
                destruct(this_object());
        }
        return 1;
}
int query_autoload(){ return 1; }