// si-huochan.c

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
        set_name(HIW"�����"NOR, ({"si huochan", "corpse"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
       
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
         {
               this_player()->add("max_neili", 5);
                 message_vision(HIY "$N����һֻ����󸣬��Ȼ��ֻ��һ�ɵ�����ֱ�嶥��...\n" NOR, this_player());
         }

        destruct(this_object());
        return 1;
}

int query_autoload() { return 1; }
